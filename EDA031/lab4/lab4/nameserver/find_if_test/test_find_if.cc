#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
 using namespace std;
int main()
{
    int hostName = 5;
 
    vector<pair<int, int> >  v;
 	v.push_back(make_pair(5,2));


    auto result1 = find_if(v.begin(), v.end(),
             [hostName](pair<int,int> m) -> int { if(m.first == hostName){return 2;} });

     if (result1 != v.end()) {
        pair<int,int> p = *result1;
         cout << p.second << '\n';
     } 
}