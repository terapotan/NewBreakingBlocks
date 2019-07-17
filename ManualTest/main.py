import unittest

class mainTest(unittest.TestCase):
    def test_showBallOnTheDisplay(self):
        self.assertEqual(input("ボールが表示されたか(y/n)"),'y')
    def test_checkBallMoveToEdgeOfScreen(self):
        self.assertEqual(input("ボールが端から端まで動いたか(y/n)"),'y')
    


# ほかのファイルからimportされたときにテストが実行されないようにする
if __name__ == "__main__":
    unittest.main()