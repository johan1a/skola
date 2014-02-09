#include <string>
#include <vector>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t) : word(w), trigrams(t) {}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int count = 0;
	string t1, t2;
	for(size_t i = 0; i < t.size(); i++){
		t1 = t[i];
		for(size_t j = 0; j < trigrams.size();j++){			
			t2 = trigrams[j];
			if(t2.at(0)>t1.at(0)){
				break;
			}
			if(trigrams[j] == t[j]){
				++count;
			}
		}
	}
	return 0;
}

vector<std:string> Word::get_trigrams(){
	return trigrams;
}