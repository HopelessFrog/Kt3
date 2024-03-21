#include "Counter.h"
#include <string>

std::vector<std::string> CountAll(std::vector<char> all_text)
{
	std::vector<std::string> SWLA;
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
	SWLA.emplace_back("Sym = " + std::to_string(symbols) + "\n");
	SWLA.emplace_back("Words = " + std::to_string(words) + "\n");
	SWLA.emplace_back("Lines = " + std::to_string(lines) + "\n");
	SWLA.emplace_back("Paragraph = " + std::to_string(paragraph) + "\n");

	return SWLA;
}
