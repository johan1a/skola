#include <iostream>
#include <string>
using namespace std;

int main() {
	int m = 100000;	
	string s(m,'P');
	s[0] = 'C';
	s[1] = 'C';
	int prime_nbr = 2;
	while(prime_nbr < m){
		for(int i = 2; i*prime_nbr < m; i++){
			s[i*prime_nbr] = 'C';
		}
		++prime_nbr;
		while(prime_nbr < m -1){
			if(s[prime_nbr] == 'P'){
				break;
			}
			++prime_nbr;
		}
	}

	cout << "Primes under 200: " << endl;
	for(int i = 2; i < 200; i++){
		if(s[i] == 'P'){
			cout << i << " ";
		}
	}
	cout << endl << endl;
	int i = m - 1;
	while(s[i] == 'C'){
		--i;
	}
	cout << "Biggest prime under " << m << ": " << i << endl;
	cout << endl;
}