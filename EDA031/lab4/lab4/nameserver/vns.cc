#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "vns.h"

using namespace std;
	VNS::VNS(){}
	VNS::~VNS(){}

	NameServerInterface::~NameServerInterface(){}
	void VNS::insert(const HostName& h, const IPAddress& ip){
		pair<HostName, IPAddress > p;
		p = std::make_pair(h, ip);
		pairs.push_back(p);
	}
	bool VNS::remove(const HostName& hostName) {
	    auto result = find_if(pairs.begin(), pairs.end(),
	             [hostName](pair<HostName,IPAddress> pair) { return pair.first == hostName;});

	      if (result != pairs.end()) {
	          pairs.erase(result);
	          return true;
	      } 
		return false;
	}

	IPAddress VNS::lookup(const HostName& hostName)  const{
	    auto result = find_if(pairs.begin(), pairs.end(),
	             [hostName](pair<HostName,IPAddress> pair) { return pair.first == hostName;});
	      if (result != pairs.end()) {
	         pair<HostName,IPAddress> p = *result;
	          return p.second;
	      } 
	      return NON_EXISTING_ADDRESS;
	}