
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
using namespace std;

Dictionary::Dictionary() {
	const char* inFileName = "words.txt";
	ifstream infile(inFileName);

	string line,word;
	char c;
 	while(infile.peek() != EOF){
 		getline(infile,line);
 		word = "";
 		size_t i = 0;
 		c = line.at(i);

 		while(c != ' '){
 			word = word + c;
 			i++;
 			c = line.at(i);
 		}

 		i += 2; // skip number of trigrams

 		string trigram;
 		vector<string> trigrams;
 		while(i < line.size()){
 			trigram = "";
 			while(c != ' '){
 				trigram = trigram + c;
 				i++;
 				c = line.at(i);
 			}
 			trigrams.push_back(trigram);
 		}
		words[word.size()].push_back(Word(word,trigrams));
 	}
}

void Dictionary::add_trigram_suggestions(const string& word){
	size_t wordLength = word.size()-1;
	//suggestions = vector<string>;
	for(size_t i = 0; i < 3; i++){
		wordLength = wordLength + i;
		if(wordLength == 0 || wordLength > max_word_length){
			break;
		}
		for(Word w : words[wordLength]){
			if(w.get_matches(word) > 2){
				suggestions.push_back(word);
			}
		}
	}
}

void rank_suggestions(){

}


bool Dictionary::contains(const string& word) const {
	return false;
	//return words[word.size()].find(word) != words.end();;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	return suggestions;
}
