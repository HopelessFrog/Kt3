#include "SaveInfo.h"

void SaveInfo(std::vector<std::string> text_info, std::vector<SentencesCounter> sentences_info)
{
	std::ofstream FileRecorder = CheckFile();
	for (int i = 0; i < text_info.size(); i++)
		FileRecorder << text_info[i];
	for (int i = 0; i < sentences_info.size(); i++)
		FileRecorder << sentences_info[i].ReturnInfo();
	FileRecorder.close();
}
