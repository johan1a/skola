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

private:
	static const size_t max_word_length = 25;
	void add_trigram_suggestions(std::vector<Word>& suggestions, const std::string& word) const;
	void rank_suggestions(std::vector<Word>& suggestions, const std::string& word) const;
	void trim_suggestions(std::vector<Word>& suggestions) const;
	std::vector<Word> words[max_word_length];
};

#endif
