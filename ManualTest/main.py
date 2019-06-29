import unittest

class mainTest(unittest.TestCase):
    def test_checkShowBarImage(self):
        self.assertEqual(input("バーの画像は表示されたか。(y/n)"),'y')
    def test_checkShowBlockImage(self):
        self.assertEqual(input("ブロックの画像は表示されたか。(y/n)"),'y')
    def test_checkShowBallImage(self):
        self.assertEqual(input("ボールの画像は表示されたか。(y/n)"),'y')


# ほかのファイルからimportされたときにテストが実行されないようにする
if __name__ == "__main__":
    unittest.main()