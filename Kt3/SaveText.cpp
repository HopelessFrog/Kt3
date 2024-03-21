#include "SaveText.h"
#include "Check.h"
#include "CheckFile.h"

void SaveText(std::vector<char> all_text)
{
	std::ofstream FileRecorder = CheckFile();
	for (int i = 0; i < all_text.size(); i++)
		FileRecorder << all_text[i];
	FileRecorder.close();
}
