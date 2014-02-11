#include <string>
#include <vector>
#include <iostream>
#include "word.h"

using namespace std;
Word::Word(){}
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

			if(t1.at(0) > t2.at(0)){
				continue;	
			}
			if(t1 == t2){
				++count;
			}
		}
	}
	return count;
}

vector<string> Word::get_trigrams(){
	return trigrams;
}