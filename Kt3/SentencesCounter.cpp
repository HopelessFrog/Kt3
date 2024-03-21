#include "SentencesCounter.h"

int SentencesCounter::GetcountOfWords()
{
	return countOfWords;
}

void SentencesCounter::PrintInfo()
{
	std::cout << "Sentences with " << countOfWords << " words - " << CountOfSent << std::endl;
}


void SentencesCounter::PlusCount()
{
	CountOfSent++;
}

std::string SentencesCounter::ReturnInfo()
{
	return "Sentences with " + std::to_string(countOfWords) + " words - " + std::to_string(CountOfSent) + "\n";
}
