import sys
import os
relative_path = os.path.join(os.path.dirname(__file__), '..', 'build')
sys.path.append(relative_path)

from MatVec import MatVec as mv
import MatVec as MM

print("mv( [1] )")
mv([1])
print("mv([[1],[2]])")
mv([[1,2],[2,3]])