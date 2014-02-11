#include <vector>
#include <istream>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
//	const char* fileName = "/usr/share/dict/words";
	ifstream infile("test.txt");
	ofstream outfile;
 	outfile.open("words.txt");

	string word;
 	while(infile >> word){
 		vector<string> trigrams;
 		for(unsigned int i = 0; i  < word.size()-2 ;i++){
 			trigrams.push_back(word.substr(i,3));
		}
		std::sort(trigrams.begin(),trigrams.end());
		
		int size = trigrams.size();
 		outfile << word << " " << size << " ";
 		for(int i = 0; i < size; i++){
 			outfile << trigrams[i]<< " ";
 		}
 		outfile << endl;
 	}
 	infile.close();
 	outfile.close();
}