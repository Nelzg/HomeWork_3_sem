#pragma once
#include <iostream>
#include <fstream>
#include "PrepareWord.h"
#include <algorithm>
#include <vector>
using namespace std;

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
		struct Statistics {
			int count;
			string name;
		};
		vector<Statistics> s;
		
		Statistics elem;
		for (map<string, int>::iterator it = wordmap.begin(); it != wordmap.end(); ++it) {
			elem.name = it -> first;
			elem.count = it -> second;
			s.push_back(elem);
		}
		for (int it = 0; it < s.size() - 1; it++) {
			for (int jt = 0; jt < s.size() - it - 1; jt++) {
				if (s[jt].count >= s[jt+1].count) {
					elem = s[jt];
					s[jt] = s[jt+1];
					s[jt+1] = elem;
				}
			}
		}
		for (int it = 0; it != s.size(); ++it) {
			cout << s[it].name << " " << s[it].count << "\n";
		}
		file.close();
	}
};