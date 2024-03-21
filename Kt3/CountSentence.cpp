#include "CountSentence.h"

std::vector<SentencesCounter> CountSentence(std::vector<char> all_text)
{
	std::vector<SentencesCounter> counters;
	int sent_words = 0;
	for (int i = 1; i < all_text.size(); i++)
	{
		if (!isalpha(all_text[i]) && isalpha(all_text[i - 1]))
			sent_words++;
		if (all_text[i] == '!' || all_text[i] == '?' || all_text[i] == '.' || i == all_text.size() - 1 && sent_words > 0)
		{
			bool find = false;
			for (int j = 0; j < counters.size(); j++)
			{
				if (counters[j].GetcountOfWords() == sent_words)
				{
					counters[j].PlusCount();
					find = true;
				}
			}
			if (find)
			{
				sent_words = 0;
				continue;
			}
			counters.emplace_back(SentencesCounter(sent_words));
			sent_words = 0;
		}
	}
	return counters;
}
