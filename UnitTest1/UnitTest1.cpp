#include "CppUnitTest.h"
#include "../Kt3/Counter.h"
#include "../Kt3/Counter.cpp"
#include "../Kt3/CountSentence.h"
#include "../Kt3/CountSentence.cpp"
#include "../Kt3/SentencesCounter.h"
#include "../Kt3/SentencesCounter.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	private:
		bool listComparison(std::vector<int> list1, std::vector<int> list2, int tempSize)
		{
			for (int i = 0; i < tempSize; i++)
				if (list1[i] != list2[i])
					return false;
			return true;
		}

		std::vector<char> charVector{
			'q', 'w', 'e', 'q', 'w', 'e', '.', 'w', 'q', 'e', 'q', '.', '\n', ' ', 'q', 'w', 'e', 'w', 'e', 'q', 'q',
			'w', 'e', '.'
		};

		std::vector<int> testArray = {23, 3, 1, 1};
		SentencesCounter test = SentencesCounter(1);

	public:
		TEST_METHOD(TestMethod1)
		{
			std::vector<int> qwe = CountAll(charVector);
			Assert::IsTrue(listComparison(testArray, CountAll(charVector), 4));
		}

		TEST_METHOD(TestMethod2)
		{
			test.PlusCount();
			test.PlusCount();
			test.PlusCount();
			std::vector<SentencesCounter> qwe = CountSentence(charVector);
			Assert::IsTrue(CountSentence(charVector)[0].GetcountOfWords() == test.GetcountOfWords());
		}
	};
}
