#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include "dictionary.h"

using namespace std;

int main() {
	Dictionary dict;
	string word;

	while (cin >> word) {
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		if (dict.contains(word)) {
			cout << "Correct." << endl;
		} else {
			vector<string> suggestions = dict.get_suggestions(word);
			if (suggestions.empty()) {
				cout << "Wrong, no suggestions." << endl;
			} else {
				cout << "Wrong. Suggestions:" << endl;
				for(size_t i = 0; i  < suggestions.size() ;i++){
					cout << "    " << suggestions[i] << endl;
				}
			}
		}
	}
}
