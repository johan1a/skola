#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <stdexcept> 
#include "umns.h"

using namespace std;
UMNS::UMNS(){}
UMNS::~UMNS(){}
void UMNS::insert(const HostName& h, const IPAddress& ip){
	pair<HostName, IPAddress > p;
	p = std::make_pair(h, ip);
	pairs.insert(p);
}

bool UMNS::remove(const HostName& hostName) {
	auto result = pairs.find(hostName);
	if(result!= pairs.end()){
		pairs.erase(result);
		return true;
	}
	return false;
}

IPAddress UMNS::lookup(const HostName& hostName)  const{
	auto result = pairs.find(hostName);
	if(result!= pairs.end()){
		return result->second;
	}
	return NON_EXISTING_ADDRESS;
}
