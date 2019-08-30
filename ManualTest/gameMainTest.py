import unittest

class mainTest(unittest.TestCase): 
    def test_showBallOnTheDisplay(self):
        self.assertEqual(input("ボールが表示されたか(y/n)"),'y')
    def test_showBarOnTheDisplay(self):
        self.assertEqual(input('バーが表示されたか(y/n)'),'y')
    def test_inputKeyAndMoveLeftBar(self):
        self.assertEqual(input('バーが左矢印を押したら左にいくか(y/n)'),'y')
    def test_inputKeyAndMoveRightBar(self):
        self.assertEqual(input('バーが右矢印を押したら右に行くか(y/n)'),'y')
#    def test_showBlockOnTheDisplay(self):
#        self.assertEqual(input('ブロックが表示されたか(y/n)'),'y')


# ほかのファイルからimportされたときにテストが実行されないようにする
if __name__ == "__main__":
    unittest.main()