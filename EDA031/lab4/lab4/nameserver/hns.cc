#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdexcept> 
#include "hns.h"

using namespace std;
HNS::HNS(int s):size(s){
	for(int i = 0 ; i < size ; i++){
		vector<pair<HostName,IPAddress> > v;
		pairs.push_back(v);
	}
}
HNS::~HNS(){}

void HNS::insert(const HostName& h, const IPAddress& ip){
	pair<HostName, IPAddress > p;
	p = std::make_pair(h, ip);

	vector<pair<HostName, IPAddress> >& v = pairs[hash_code(h)];
	v.push_back(p);
}

bool HNS::remove(const HostName& hostName) {
	int i = hash_code(hostName);
	vector<pair<HostName, IPAddress> > &v = pairs[i];

	auto result = find_if(v.begin(), v.end(),
		[hostName](pair<HostName,IPAddress> pair) { return pair.first == hostName;});

	if (result != v.end()) {
		v.erase(result);
		return true;
	} 
	return false;
}

IPAddress HNS::lookup(const HostName& hostName)  const{
	int i = hash_code(hostName);


	vector<pair<HostName, IPAddress> > v = pairs[i];

	auto result = find_if(v.begin(), v.end(),
		[hostName](pair<HostName,IPAddress> pair) { return pair.first == hostName;});
	if (result != v.end()) {
		pair<HostName,IPAddress> p = *result;

		return p.second;
	} 
	return NON_EXISTING_ADDRESS;
}

int HNS::hash_code(const HostName& h) const{
	return hash<string>()(h) % size;
}

