import sys
import os
relative_path = os.path.join(os.path.dirname(__file__), '..', 'build')
sys.path.append(relative_path)


import MatVec as m # type: ignore