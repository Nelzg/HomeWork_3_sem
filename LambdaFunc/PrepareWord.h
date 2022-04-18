#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

class PrepareWord
{
	public:
		static string prepare(string& word)
		{
			string result;
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			auto noSpaceEnd = remove(word.begin(), word.end(), ' ');
			word.erase(noSpaceEnd, word.end());
			if (!((word[word.length()-1] <= 'z') && (word[word.length()-1] >= 'a'))){
				word.pop_back();
			}
			if (!((word[0] <= 'z') && (word[0] >= 'a'))) {
				word.erase(0,1);
			}
		return word;
		}
};

