#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "test_rank_grejs.h"

using namespace std;



int main(){
	test_rank_grejs t;
	cout << "hej" << endl;
	t.rank_suggestions();
}

void test_rank_grejs::rank_suggestions(){
	string test1 = "abc";
	string test2 = "cac";

	testp = test1;
	testq = test2;

	int i = testp.size();
	int j = testq.size();

	d[i][0] = i;
	d[0][j] = j;
	//delete(d);
	//d[26][26];

	cout << distance(i,j) << endl;
	cout << d[0][j];
}

int test_rank_grejs::distance(int i, int j){
	if(i == 0 && j == 0 || i < 0  || j < 0){
		return 0;
	}

	int a,b,c,min;

	if(testp.at(i-1) == testq.at(j-1)){
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
