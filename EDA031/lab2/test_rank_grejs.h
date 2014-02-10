#ifndef TEST_RANK_GREJS_H
#define TEST_RANK_GREJS_H

#include <string>
#include <vector>
class test_rank_grejs{
	public:
		int d[26][26];
		int distance(int i, int j);
		void rank_suggestions();

	private:
		std::string testp,testq;
};
#endif