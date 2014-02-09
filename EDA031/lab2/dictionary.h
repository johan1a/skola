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
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
	static const size_t max_word_length = 25;
	std::vector<Word> words[max_word_length];
	std::vector<Word> suggestions;
	void add_trigram_suggestions(const std::string& word);
	void rank_suggestons();
};

#endif
