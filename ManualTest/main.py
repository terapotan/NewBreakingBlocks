import unittest

class mainTest(unittest.TestCase):
    def test_checkShowbarBlockBallSingleRow(self):
        self.assertEqual(input("ボール、バー、ブロックが縦一列に表示されている。(y/n)"),'y')


# ほかのファイルからimportされたときにテストが実行されないようにする
if __name__ == "__main__":
    unittest.main()