#include "Matrix.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

Matrix* Matrix::readCSV(const std::string& filepath, DTypes type)
{
    std::ifstream file(filepath);
    std::string line;
    int rowCount = 0, colCount = 0;
    if (file.is_open()) 
    {
        if (std::getline(file, line)) 
        {
            std::stringstream ss(line);
            std::string value;
            while (std::getline(ss, value, ',')) 
            {
                colCount++;
            }
        }
        while (std::getline(file, line)) 
        {
            rowCount++;
        }
        rowCount++;
        file.close();
    }
    else 
    {
        throw std::runtime_error("File Can't be Opened");
    }
    std::vector<int> shape = { rowCount, colCount };
    Matrix* m = new Matrix(shape, type);

    std::ifstream file1(filepath);
    if (file1.is_open()) 
    {
        std::string line1;
        unsigned long long int i = 0;
        while (std::getline(file1, line1)) {
            std::stringstream ss(line1);
            std::string value;
            while (std::getline(ss, value, ',')) 
            {
                //std::cout << "Hello" << value << std::endl;
                switch (type)
                {
                case Int8:
                    static_cast<dInt8*>(m->matrix)[i] = static_cast<dInt8>(std::stoi(value));
                    break;
                case Int16:
                    static_cast<dInt16*>(m->matrix)[i] = static_cast<dInt16>(std::stoi(value));
                    break;
                case Int32:
                    static_cast<dInt32*>(m->matrix)[i] = static_cast<dInt32>(std::stoi(value));
                    break;
                case Int64:
                    static_cast<dInt64*>(m->matrix)[i] = static_cast<dInt64>(std::stoi(value));
                    break;
                case Real32:
                    static_cast<dReal32*>(m->matrix)[i] = static_cast<dReal32>(std::stod(value));
                    break;
                case Real64:
                    static_cast<dReal64*>(m->matrix)[i] = static_cast<dReal64>(std::stod(value));
                    break;
                case Real64T:
                    static_cast<dReal64T*>(m->matrix)[i] = static_cast<dReal64T>(std::stod(value));
                    break;
                default:
                    static_cast<dReal64*>(m->matrix)[i] = static_cast<dReal64>(std::stod(value));
                    break;
                }
                i++;
            }
        }

        file.close();
    }
    else 
    {
        std::cerr << "Unable to open file" << std::endl;
    }
    return m;
}

template<typename T>
bool writeArrayToCSV(const T* array, int rowSize, const std::string& filename, int elements);

bool Matrix::writeCSV(const std::string& filepath, Matrix* m) {
    switch (m->type) {
    case DTypes::Int8:
        return writeArrayToCSV(static_cast<int8_t*>(m->matrix), m->shape[0], filepath, m->elements);
    case DTypes::Int16:
        return writeArrayToCSV(static_cast<int16_t*>(m->matrix), m->shape[0], filepath, m->elements);
    case DTypes::Int32:
        return writeArrayToCSV(static_cast<int32_t*>(m->matrix), m->shape[0], filepath, m->elements);
    case DTypes::Int64:
        return writeArrayToCSV(static_cast<int64_t*>(m->matrix), m->shape[0], filepath, m->elements);
    case DTypes::Real32:
        return writeArrayToCSV(static_cast<float*>(m->matrix), m->shape[0], filepath, m->elements);
    case DTypes::Real64:
        return writeArrayToCSV(static_cast<double*>(m->matrix), m->shape[0], filepath, m->elements);
    case DTypes::Real64T:
        return writeArrayToCSV(static_cast<long double*>(m->matrix), m->shape[0], filepath, m->elements);
    default:
        return writeArrayToCSV(static_cast<double*>(m->matrix), m->shape[0], filepath, m->elements);
    }
}


template<typename T>
bool writeArrayToCSV(const T* array, int rowSize, const std::string& filename, int elements) 
{
    int rows = elements / rowSize;
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < rowSize; ++j) 
        {
            file << array[i * rowSize + j];
            if (j < rowSize - 1) 
            {
                file << ", ";
            }
        }
        if (i < rows - 1)
        {
            file << "\n"; // New line at the end of each row
        }
    }

    file.close();
    return true;
}

template bool writeArrayToCSV<int8_t>(const int8_t* array, int rowSize, const std::string& filename, int elements);
template bool writeArrayToCSV<int16_t>(const int16_t* array, int rowSize, const std::string& filename, int elements);
template bool writeArrayToCSV<int32_t>(const int32_t* array, int rowSize, const std::string& filename, int elements);
template bool writeArrayToCSV<int64_t>(const int64_t* array, int rowSize, const std::string& filename, int elements);
template bool writeArrayToCSV<float>(const float* array, int rowSize, const std::string& filename, int elements);
template bool writeArrayToCSV<double>(const double* array, int rowSize, const std::string& filename, int elements);
template bool writeArrayToCSV<long double>(const long double* array, int rowSize, const std::string& filename, int elements);
