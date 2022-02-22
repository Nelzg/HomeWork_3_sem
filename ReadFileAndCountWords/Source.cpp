#include <string>
#include "GetFileWords.h"
using namespace std;

int main() {
	string filename = "aboba.txt";
	GetFileWords::getWords(filename);
	return 0;
}