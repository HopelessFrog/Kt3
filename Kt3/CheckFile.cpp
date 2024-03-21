#include "CheckFile.h"
#include <filesystem>
#include <Windows.h>
#include <ShlObj_core.h>


bool IsLegalFileName(std::string name)
{
	std::wstring widestr = std::wstring(name.begin(), name.end());
	const wchar_t* filename = widestr.c_str();
	WCHAR valid_invalid[MAX_PATH];
	wcscpy_s(valid_invalid, filename);

	int result = PathCleanupSpec(nullptr, valid_invalid);

	return result == 0 && _wcsicmp(valid_invalid, filename) == 0;
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
		try
		{
			if (!IsLegalFileName(name)) {
				std::cout << "File is a system file." << std::endl;
				continue;
			}
			CheckFileExist.open(name);
			std::cout << "A file with the same name already exists. " << std::endl
				<< "1 - Save in this file " << std::endl
				<< "2 - Chose another name " << std::endl;
			int var = CheckMenu(2);
			if (var == this_file)
			{
				FileRecorder.open(name);
				CheckFileExist.close();
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
