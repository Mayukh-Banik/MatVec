import unittest
import matrix as mp

class Test_test_CreateInstances(unittest.TestCase):
    def test_A(self):
        try:
            a = mp.matrix.identity(5)
            print(a)
        except Exception:
            self.fail("test_A")


if __name__ == '__main__':
    unittest.main()