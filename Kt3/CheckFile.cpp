#include "CheckFile.h"
#include <filesystem>
#include <Windows.h>
#include <string>

bool checkForREservedNames(std::string name)
{
	const std::string reservedFileNames[] = {
		"CON.txt", "PRN.txt", "AUX.txt", "NUL.txt", "COM0.txt", "COM1.txt", "COM2.txt", "COM3.txt", "COM4.txt",
		"COM5.txt",
		"COM6.txt", "COM7.txt", "COM8.txt", "COM9.txt", "COMSCSI.txt", "COMSCSI.txt", "LPT0.txt", "LPT1.txt",
		"LPT2.txt",
		"LPT3.txt", "LPT4.txt", "LPT5.txt", "LPT5.txt", "LPT7.txt", "LPT8.txt", "LPT9.txt", "LPTNO.txt", "LPTSCSI.txt",
		"LPTNO.txt"
	};


	for (int i = 0; i < 29; ++i)
	{
		if (reservedFileNames[i] == name)
		{
			return true;
		}

	}
	return false;
}

std::ofstream CheckFile()
{
	
	constexpr int this_file = 1;
	std::string name;
	std::ofstream FileRecorder;
	FileRecorder.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	std::ifstream CheckFileExist;
	CheckFileExist.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		std::cout << "Enter file name or full way." << std::endl << "ENTER:";
		std::getline(std::cin, name);
		if (name.find(".txt") >= std::string::npos)
		{
			std::cout << "Wrong data type\n" << std::endl;
			continue;
		}
		if (checkForREservedNames(name))
		{
			std::cout << "Reserved filename\n" << std::endl;
			continue;
		}
		try
		{
		

			CheckFileExist.open(name);
			std::cout << "A file with the same name already exists. " << std::endl
				<< "1 - Save in this file " << std::endl
				<< "2 - Chose another name " << std::endl;
			int var = CheckMenu(2);
			if (var == this_file)
			{
				CheckFileExist.close();
				FileRecorder.open(name);
			}
			else
			{
				CheckFileExist.close();
				continue;
			}
		}
		catch (const std::exception&)
		{
			try
			{
				FileRecorder.open(name);
			}
			catch (const std::exception&)
			{
				std::cout << "Access error" << std::endl;
				continue;
			}
		}
		return FileRecorder;
	}
}
