#include "InputFileText.h"

std::vector<char> InputFileText()
{
	std::string file_name = "";
	std::ifstream file;
	std::vector<char> all_text;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		std::cout << "Enter file name. " << std::endl << "ENTER : ";
		std::cin >> file_name;
		if (file_name.find(".txt") >= std::string::npos)
		{
			std::cout << "Wrong data type\n" << std::endl;
			continue;
		}
		try
		{
			file.open(file_name);
			std::cout << "successful file open " << std::endl;
			break;
		}
		catch (const std::exception&)
		{
			std::cout << "Incorrect file name or way.Try again ." << std::endl;
		}
	}
	char ch;
	while (true)
	{
		try
		{
			file.get(ch);
		}
		catch (const std::exception&)
		{
			break;
		}

		all_text.push_back(ch);
	}
	file.close();
	std::cin.clear();
	std::cin.ignore();
	return all_text;
}
