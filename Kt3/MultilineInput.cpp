#include "MultilineInput.h"
#include <vector>
#include <conio.h>
#include <Windows.h>
#include "SentencesCounter.h"


enum keys
{
	enter = 13,
	backspace = 8
};

std::vector<char> MultilineInput()
{
	setlocale(LC_ALL, "Russian");
	int symbols = 0;
	int words = 0;
	int lines = 0;
	int abzac = 0;
	int sentensis = 0;
	std::vector<char> all_text;
	all_text.push_back('\n');
	char temp_char;
	int i;
	while (true)
	{
		i = static_cast<int>(all_text.size());
		temp_char = 0;
		system("cls");
		std::cout << "Enter : ";
		for (int j = 1; j < all_text.size(); j++)
		{
			std::cout << all_text[j];
		}

		temp_char = _getch();
		if (temp_char < 0)
		{
			std::cout << "\nThe program does not support Russian characters or special symbols" << std::endl;
			std::cin.sync();
			system("pause");
			continue;
		}
		if (static_cast<int>(temp_char) == enter)
		{
			if (i > 0)
				if (all_text[i - 1] == '\n')
					break;
			all_text.push_back('\n');
			continue;
		}
		if (static_cast<int>(temp_char) == backspace)
		{
			if (all_text.size() > 0)
			{
				all_text.erase(all_text.begin() + i - 1);
			}
			continue;
		}
		all_text.push_back(temp_char);
	}

	return all_text;
}
