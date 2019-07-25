import unittest

class mainTest(unittest.TestCase):
    def test_showBallOnTheDisplay(self):
        self.assertEqual(input("ボールが表示されたか(y/n)"),'y')
    def test_checkBallKeyActionMove(self):
        self.assertEqual(input("aキーを入力するとボールが右へ移動する(y/n)"),'y')
    


# ほかのファイルからimportされたときにテストが実行されないようにする
if __name__ == "__main__":
    unittest.main()