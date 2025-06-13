#pragma once
#include <map>
#include <vector>
#include <CString>

enum class WordCategory {
	Words,
	CompoundWords,
	Noun,
	Verb,
	Adjective,
	Adverb,
	Other
};

extern std::map<WordCategory, std::vector<CString>> g_EnglishWords;
extern std::map<WordCategory, std::vector<CString>> g_KoreanMeanings;

void LoadWordDB(const CString& iniPath);