#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "coding.h"
using namespace std;

int main(int argc, char* argv[]){
	//string filename = argv[0];
	string filename  = argv[1];
 	ifstream infile(filename.c_str());

 	ofstream outfile;
 	string outname = filename + ".enc";
 	outfile.open(outname.c_str());
	
	unsigned char c;
 	unsigned char c_enc;
 	while(infile.peek() != EOF){
 		c =  infile.get();
		c_enc = Coding::encode(c);
		outfile.put(c_enc);
	}
	infile.close();
	outfile.close();
}