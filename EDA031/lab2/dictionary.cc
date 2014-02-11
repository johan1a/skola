
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

vector<Word> Dictionary::get_suggestions(const string& word) const {
	vector<Word> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<Word>& suggestions, const string& word) const{
	size_t wordLength = word.size()-1;

	//todo flytta till metod
	vector<string> word_trigrams;
 	for(unsigned int i = 0; i  < word.size()-2 ;i++){
 		word_trigrams.push_back(word.substr(i,3));
	}
	std::sort(word_trigrams.begin(),word_trigrams.end());

	//suggestions = vector<string>;
	for(size_t i = 0; i < 3; i++){
		wordLength = wordLength + i;
		if(wordLength == 0 || wordLength > max_word_length){
			break;
		}
		vector<Word> word_list = words[wordLength];
		for(size_t j = 0; j < word_list.size();j++){
			Word w = word_list[j];
			if(w.get_matches(word_trigrams) > 2){
				suggestions.push_back(w);
			}
		}
	}
}

struct Distance_Comparator {
	const string& word;
	string word_to_compare;   
	int d[26][26];

    Distance_Comparator(const string& w) : word(w){}

    bool operator () ( const Word & sugg1, const Word & sugg2 ) {
    	word_to_compare = sugg1.get_word();
		int d_1 =  distance(word_to_compare.size(),word.size());

		word_to_compare = sugg2.get_word();
		int d_2 = distance(word_to_compare.size(),word.size());
		return d_1 >= d_2;
	}

	int distance(int i, int j){
		if(j == 0){
			return i;
		}else if(i == 0){
			return j;
		}

		int a,b,c,min;

		if(word_to_compare.at(i-1) == word.at(j-1)){
			a = distance(i-1,j-1);
		}else{
			a = distance(i-1,j-1) + 1;
		}
		b = distance(i-1,j)+1;
		c = distance(i,j-1)+1;

		if(a < b){
			if(a < c){
				min = a;
			}else{
				min = c;
			}
		}else if(b < c){
			min = c;
		}else{
			min = b;
		}

		d[i][j] = min;
		return min;
	}
};


void Dictionary::rank_suggestions(vector<Word>& suggestions, const string& word) const{
	sort(suggestions.begin(),suggestions.end(),Distance_Comparator(word));
}

void Dictionary::trim_suggestions(vector<Word>& suggestions) const{
	// if(suggestions.size()> 5){
	// 	suggestions.resize(5);
	// }
}

bool Dictionary::contains(const string& word) const {
	for(size_t i = 0; i < max_word_length; i++){
		vector<Word> v = words[i];
		string s;
		for(size_t j = 0; j < v.size(); j++){
			s = v[j].get_word();
			if(word == s){
				return true;
			}
		}
	}
	return  false;
}
