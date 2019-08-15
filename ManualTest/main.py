import unittest

class mainTest(unittest.TestCase):
    def test_showBallOnTheDisplay(self):
        self.assertEqual(input("ボールが表示されたか(y/n)"),'y')
    def test_showBarOnTheDisplay(self):
        self.assertEqual(input('バーが表示されたか(y/n)'),'y')
    def test_moveBarDisplayOfEdge(self):
        self.assertEqual(input('バーが画面の端から端まで動いているか(y/n)'),'y')
#    def test_showBarAndBallOverlap(self):
#        self.assertEqual(input('ボールとバーが重なって表示されているか(y/n)'),'y')
#    def test_checkCollectBallAndBarCollision(self):
#        self.assertEqual(input('collisionCheck:1と表示されているか(y/n)'),'y')
#    def test_checkShowImageLoadError(self):
#       self.assertEqual(input('ボールの画像ファイル読み込みに失敗したときにエラーメッセージが出るか(y/n)'),'y')
#    def test_checkCollectErrorMessage(self):
#        self.assertEqual(input('エラーメッセージに読み込み失敗の旨と対処法が書かれているか(y/n)'),'y')
# ほかのファイルからimportされたときにテストが実行されないようにする
if __name__ == "__main__":
    unittest.main()