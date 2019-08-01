#include "CppUnitTest.h"
#include "../NewBreakingBlocksConsole/Tested.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NewBreakingBlocksConsoleTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(test(1, 2), 4);
		}

	};
}