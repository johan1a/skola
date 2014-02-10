#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"
class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<Word> get_suggestions(const std::string& word) const;

	void rank_suggestions();
private:
	static const size_t max_word_length = 25;
	int d[26][26];
	std::string testp;
	std::string testq;
	std::vector<Word> words[max_word_length];
	std::vector<Word> suggestions;
	void add_trigram_suggestions(const std::string& word);
	int distance(int i, int j);
};

#endif
