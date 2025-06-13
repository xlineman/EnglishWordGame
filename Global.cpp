#include "stdafx.h"
#include "Global.h"
#include <Windows.h>
#include <tchar.h>


std::map<WordCategory, std::vector<CString>> g_EnglishWords;
std::map<WordCategory, std::vector<CString>> g_KoreanMeanings;

// 카테고리 enum -> INI 섹션 이름
static std::map<WordCategory, CString> CategoryToSection = {
	{ WordCategory::Words, _T("Words") },
{ WordCategory::CompoundWords, _T("Compound Words") },
{ WordCategory::Noun, _T("Noun") },
{ WordCategory::Verb, _T("Verb") },
{ WordCategory::Adjective, _T("Adjective") },
{ WordCategory::Adverb, _T("Adverb") },
{ WordCategory::Other, _T("Other") }
};

void LoadWordDB(const CString& iniPath)
{
	for (auto it = CategoryToSection.begin(); it != CategoryToSection.end(); ++it)
	{
		WordCategory category = it->first;
		CString sectionName = it->second;

		TCHAR buffer[4096] = { 0 };
		DWORD len = GetPrivateProfileSection(sectionName, buffer, 4096, iniPath);
		if (len == 0) continue;

		std::vector<CString> engList, korList;
		TCHAR* ptr = buffer;
		while (*ptr)
		{
			CString line = ptr;
			int pos = line.Find(_T('='));
			if (pos >= 0)
			{
				CString eng = line.Left(pos).Trim();
				CString kor = line.Mid(pos + 1).Trim();
				engList.push_back(eng);
				korList.push_back(kor);
			}
			ptr += _tcslen(ptr) + 1;
		}

		g_EnglishWords[category] = engList;
		g_KoreanMeanings[category] = korList;
	}
}
