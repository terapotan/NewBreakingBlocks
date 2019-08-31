import unittest

class mainTest(unittest.TestCase):
    def test_checkCollectBallAndBarNoCollision(self):
        self.assertEqual(input('ボールとバーが重なっていない時にcollisionCheck:1が表示されていないか(y/n)'),'y')
    def test_checkCollectBallAndBarCollision(self):
        self.assertEqual(input('ボールとバーが重なっているときにcollisionCheck:1となっているか(y/n)'),'y')    


# ほかのファイルからimportされたときにテストが実行されないようにする
if __name__ == "__main__":
    unittest.main()