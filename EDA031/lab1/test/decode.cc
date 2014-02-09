#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "coding.h"
using namespace std;

int main(int argc, char* argv[]){
	string filename  = argv[1];
	
	string filename_enc = filename + ".enc";
 	ifstream infile(filename_enc.c_str());

 	ofstream outfile;
 	string outname = filename + ".dec";
 	outfile.open(outname.c_str());
	unsigned char c;
 	unsigned char c_dec;
 	while(infile.peek() != EOF){
 		c =  infile.get();
		c_dec = Coding::decode(c);
		outfile.put(c_dec);
	}
	infile.close();
	outfile.close();

}