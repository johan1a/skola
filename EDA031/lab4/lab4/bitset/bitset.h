/*
 * A Bitset is an "array of bits", stored in a word (unsigned long).
 * The word contains BPW ("bits per word") bits.
 *
 */

#ifndef BITSET_H
#define BITSET_H

#include <cstddef> /* size_t */
#include <limits>  /* numeric_limits */
#include <iterator>

 class BitReference;
 class BitsetIterator;

 class Bitset {
 	friend class BitReference;
 	friend class BitsetIterator;
 public:
 	Bitset();
 	size_t size() const;
 	bool operator[](size_t pos) const;
 	BitReference operator[](size_t pos);
 	
 	typedef BitsetIterator iterator;
 	iterator begin();
 	iterator end();
 	
 private:
 	typedef unsigned long BitStorage;
 	BitStorage bits;
 	static const size_t
 	BPW = std::numeric_limits<BitStorage>::digits;
 };

#endif
