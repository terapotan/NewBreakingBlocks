import unittest

class mainTest(unittest.TestCase):
    def test_showBallOnTheDisplay(self):
        self.assertEqual(input("ボールが表示されたか(y/n)"),'y')
    def test_showBarOnTheDisplay(self):
        self.assertEqual(input('バーが表示されたか(y/n)'),'y')
#    def test_checkCollectBallDiamater(self):
#        self.assertEqual(input('ballDiamater:52と表示されるか(y/n)'),'y')
#    def test_checkCollectBarWidth(self):
#        self.assertEqual(input('barWidth:216と表示されるか(y/n)'),'y')
#    def test_checkCollectBarHeight(self):
#        self.assertEqual(input('barHeight:28と表示されるか(y/n)'),'y')
#    def test_checkShowImageLoadError(self):
#       self.assertEqual(input('ボールの画像ファイル読み込みに失敗したときにエラーメッセージが出るか(y/n)'),'y')
#    def test_checkCollectErrorMessage(self):
#        self.assertEqual(input('エラーメッセージに読み込み失敗の旨と対処法が書かれているか(y/n)'),'y')
# ほかのファイルからimportされたときにテストが実行されないようにする
if __name__ == "__main__":
    unittest.main()