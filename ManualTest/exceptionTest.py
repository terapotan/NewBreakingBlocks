import unittest

class mainTest(unittest.TestCase):
   def test_showLoadExceptionCheck(self):
        self.assertEqual(input('画像読み込みエラーが表示されるか(y/n)'),'y')
   def test_showExpectLoadExceptionCheck(self):
        self.assertEqual(input('画像読み込みエラーが指定の形式通り表示されるか(詳細メッセージ等)(y/n)'),'y')



# ほかのファイルからimportされたときにテストが実行されないようにする
if __name__ == "__main__":
    unittest.main()