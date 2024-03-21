#include "Check.h"

int CheckMenu(int items)
{
	std::string value_input;
	int value;
	while (true)
	{
		std::cout << "ENTER : ";
		std::getline(std::cin, value_input);

		try
		{
			value = stoi(value_input);
			if (value <= items && value >= 1)
				return value;
			throw value;
		}
		catch (std::exception&)
		{
			std::cout << "Non-existent menu item.Try again. " << std::endl;
		}
		catch (int ex_value)
		{
			std::cout << ex_value << " menu item does not exist.Try again." << std::endl;
		}
	}
}
