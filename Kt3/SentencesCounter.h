#pragma once
#include <iostream>
#include <string>
class SentencesCounter
{
private:
	int CountOfSent{ 1 };
	const int countOfWords;
public:
	SentencesCounter(int count_of_words_)
		:countOfWords(count_of_words_)
	{}
	int GetcountOfWords();
	void PrintInfo();
	void PlusCount();
	std::string ReturnInfo();


};

