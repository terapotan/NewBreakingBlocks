import unittest

class mainTest(unittest.TestCase):
    def test_checkCollectEventCheckListContent(self):
        self.assertEqual(input('EventOccurCheckClassesInAFrame:dummyEventCheck1,dummyEventCheck2,dummyEventCheck3,と表示されているか(y/n)'),'y')
    def test_checkCollectEventQueueListContent(self):
        self.assertEqual(input('EventExecuteClassesInAFrame:dummyEventAction1,dummyEventAction2,dummyEventAction3,と表示されているか(y/n)'),'y')
    def test_checkCollectEventActionListCotent(self):
        self.assertEqual(input('EventExecuseList:dummyEventAction1,dummyEventAction2,dummyEventAction3,と表示されているか(y/n)'),'y')
    def test_checkCollectEventQueueListAfterCalling(self):
        self.assertEqual(input('EventAfterQueueListEmpty:Yesと表示されているか(y/n)'),'y')
    def test_checkCollectEventActionQueContent(self):
        self.assertEqual(input('EventActionQue:eventAction1,eventAction2と表示されているか(y/n)'),'y')
    def test_checkCallEventActionQueContent(self):
        self.assertEqual(input('関数呼び出し後にEventActionQue:(何も表示されない)となっているか(y/n)'),'y')



# ほかのファイルからimportされたときにテストが実行されないようにする
if __name__ == "__main__":
    unittest.main()