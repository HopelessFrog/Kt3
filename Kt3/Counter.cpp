#include "Counter.h"
#include <string>

std::vector<std::string> CountAllDecor(std::vector<char> all_text)
{
	std::vector<std::string> info;
	std::vector<int> infoValue = CountAll(all_text);

	int symbols = infoValue[0];
	int words = infoValue[1];
	int lines = infoValue[2];
	int paragraph = infoValue[3];
	info.emplace_back("Sym = " + std::to_string(symbols) + "\n");
	info.emplace_back("Words = " + std::to_string(words) + "\n");
	info.emplace_back("Lines = " + std::to_string(lines) + "\n");
	info.emplace_back("Paragraph = " + std::to_string(paragraph) + "\n");

	return info ;
}

std::vector<int> CountAll(std::vector<char> all_text)
{
	std::vector<int> info;
	int symbols = 0;
	int words = 0;
	int lines = 0;
	int paragraph = 0;

	if (all_text.size() > 1)
		symbols = static_cast<int>(all_text.size()) - 1;
	for (int i = 1; i < all_text.size(); i++)
	{
		if (!isalpha(all_text[i]) && isalpha(all_text[i - 1]))
			words++;

		if (all_text[i] == ' ' && all_text[i - 1] == '\n')
			paragraph++;
		if (all_text[i] == '\n')
			lines++;
	}
	info.emplace_back(symbols);
	info.emplace_back(words);
	info.emplace_back(lines);
	info.emplace_back(paragraph);

	return info;
}
