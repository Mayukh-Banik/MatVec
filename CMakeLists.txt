cmake_minimum_required(VERSION 3.30.0)

project(MatVec LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

include_directories(
    include
    /usr/include/python3.10
    /home/weket/.local/lib/python3.10/site-packages/pybind11/include
    /usr/local/cuda-12.4/include
)

file(GLOB_RECURSE SOURCE_FILES 
     "${CMAKE_SOURCE_DIR}/src/*.cpp"
     "${CMAKE_SOURCE_DIR}/src/*.cu")

# Specify the shared library and its source files
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

set(CMAKE_SHARED_LIBRARY_PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "MatVec")

# Compiler options for NVCC and CXX
set(MY_NVCC_FLAGS_DEBUG "-g -G -rdc=true -Xcompiler -fPIC -Werror all-warnings --generate-line-info -dc --gpu-architecture=sm_86")
set(MY_NVCC_FLAGS_RELEASE "-O3 -rdc=true -Xcompiler -fPIC -Werror all-warnings -dopt --gpu-architecture=sm_86")

set(MY_CXX_FLAGS_DEBUG "-Og -g -fPIC -Wall")
set(MY_CXX_FLAGS_RELEASE "-O3 -fPIC -Wall")

# Apply compiler flags for Debug and Release
target_compile_options(${PROJECT_NAME} PRIVATE
    "$<$<CXX_COMPILER_ID:NVIDIA>:$<$<CONFIG:Debug>:${MY_NVCC_FLAGS_DEBUG}>$<$<CONFIG:Release>:${MY_NVCC_FLAGS_RELEASE}>>"
    "$<$<NOT:$<CXX_COMPILER_ID:NVIDIA>>:$<$<CONFIG:Debug>:${MY_CXX_FLAGS_DEBUG}>$<$<CONFIG:Release>:${MY_CXX_FLAGS_RELEASE}>>"
)

# Alternatively, you can use 'set_target_properties' to set different properties
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CUDA_STANDARD 17
    COMPILE_OPTIONS "$<$<CONFIG:DEBUG>:${MY_CXX_FLAGS_DEBUG}>"
    COMPILE_OPTIONS "$<$<CONFIG:RELEASE>:${MY_CXX_FLAGS_RELEASE}>"
)
