#pragma once
#include <iostream>
#include <fstream>
#include "PrepareWord.h"
#include <algorithm>
#include <vector>
using namespace std;

struct Statistics {
	int count;
	string name;
};

bool compare_(const Statistics& lhs, const Statistics& rhs);


class GetFileWords
{
	public:
	static void getWords(string filename) {
		map<string, int> wordmap;
		ifstream file(filename);
		if (file.is_open()) {
			string word;
			while (!file.eof()) {
				file >> word;
				word = PrepareWord::prepare(word);
				if (wordmap.find(word) == wordmap.end()) {
					wordmap.insert(pair<string, int>(word, 0));
				}
				wordmap[word]++;
			}
		}

		vector<Statistics> s;
		
		Statistics elem;
		for (map<string, int>::iterator it = wordmap.begin(); it != wordmap.end(); ++it) {
			elem.name = it -> first;
			elem.count = it -> second;
			s.push_back(elem);
		}

		for (const auto& [name, count] : wordmap) {
			elem.name = name;
			elem.count = count;
			s.push_back(elem);
		}

		std::sort(s.begin(), s.end(), compare_);

		for (int it = 0; it != s.size(); ++it) {
			cout << s[it].name << " " << s[it].count << "\n";
		}
		file.close();
	}
};