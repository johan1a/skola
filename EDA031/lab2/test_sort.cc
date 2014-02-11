#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

class MyClass {
public:
    struct Less {
        Less(MyClass& c) : myClass(c) {}
        bool operator () ( const int & i1, const int & i2 ) {
        	return i1 > i2;
        } 
        MyClass& myClass;
    };
    void doSort() { 
    	vector<int> arr;
    	arr.push_back(1);
    	arr.push_back(2);
 		arr.push_back(3);
    	std::sort(arr.begin(),arr.end(), Less(*this)); 

    	cout << arr[0] << endl;
    	cout << arr[1] << endl;

    	string a = "a b c d";
    	string b;
    
    }

};

int main(){
	MyClass m;
	m.doSort();
}