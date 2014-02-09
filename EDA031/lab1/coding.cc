#include "coding.h"
using namespace std;

unsigned char Coding::encode(unsigned char c){
	return c + 90;
}

unsigned char Coding::decode(unsigned char c){
	return c - 90;
}
