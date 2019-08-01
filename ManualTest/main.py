import unittest

class mainTest(unittest.TestCase):
    def test_showBallOnTheDisplay(self):
        self.assertEqual(input("ボールが表示されたか(y/n)"),'y')
    def test_checkBallMoveEdgeOfScreen(self):
        self.assertEqual(input('ボールが端から端まで移動したか(y/n)'),'y')
    def test_checkCollectValueOfBallRadius(self):
        self.assertEqual(input('ballradius:26と表示されるか(y/n)'),'y')
#    def test_checkShowImageLoadError(self):
#       self.assertEqual(input('ボールの画像ファイル読み込みに失敗したときにエラーメッセージが出るか(y/n)'),'y')
#    def test_checkCollectErrorMessage(self):
#        self.assertEqual(input('エラーメッセージに読み込み失敗の旨と対処法が書かれているか(y/n)'),'y')
# ほかのファイルからimportされたときにテストが実行されないようにする
if __name__ == "__main__":
    unittest.main()