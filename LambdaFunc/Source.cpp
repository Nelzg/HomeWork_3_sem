#include <string>
#include "PrepareWord.h"
#include <vector>

#define N 8

using namespace std;

int main() {
	std::vector<string> strings = {"asd","asd","tasf","Asd","uojkk","tasf","poipoj","uo jkk", "tat u k r"};
	std::vector<string>::iterator it;

	transform(strings.begin(), strings.end(), strings.begin(), PrepareWord::prepare);

	sort(strings.begin(), strings.end());
	
	it = std::unique(strings.begin(), strings.end());
	
	strings.resize(std::distance(strings.begin(), it));

	for (it = strings.begin(); it < strings.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}