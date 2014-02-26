#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <stdexcept> 
#include "mns.h"

using namespace std;
MNS::MNS(){}
MNS::~MNS(){}

void MNS::insert(const HostName& h, const IPAddress& ip){
	pair<HostName, IPAddress > p;
	p = std::make_pair(h, ip);
	pairs.insert(p);
}

bool MNS::remove(const HostName& hostName) {
	auto result = pairs.find(hostName);
	if(result!= pairs.end()){
		pairs.erase(result);
		return true;
	}
	return false;
}

IPAddress MNS::lookup(const HostName& hostName)  const{
	auto result = pairs.find(hostName);
	if(result!= pairs.end()){
		return result->second;
	}
	return NON_EXISTING_ADDRESS;
}

