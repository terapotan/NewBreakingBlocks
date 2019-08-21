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
    def test_checkCollectBallAndBarNoCollision(self):
        self.assertEqual(input('ボールとバーが重なっていない時にcollisionCheck:0となっているか(y/n)'),'y')
    def test_checkCollectBallAndBarCollision(self):
        self.assertEqual(input('ボールとバーが重なっているときにcollisionCheck:1となっているか(y/n)'),'y')
    def test_checkCollectEventCheckListContent(self):
        self.assertEqual(input('EventCheckList:eventCheck1,eventCheck2,eventCheck3と表示されているか(y/n)'),'y')

#    def test_checkCollectEventActionQueContent(self):
#        self.assertEqual(input('EventActionQue:eventAction1,eventAction2と表示されているか(y/n)'),'y')
#    def test_checkCallEventActionQueContent(self):
#        self.assertEqual(input('関数呼び出し後にEventActionQue:(何も表示されない)となっているか(y/n)'),'y')
#    def test_showBlockOnTheDisplay(self):
#        self.assertEqual(input('ブロックが表示されたか(y/n)'),'y')
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