#ifndef UMNS_H
#define UMNS_H
#include "nameserverinterface.h"
#include <string>
#include <unordered_map>

class UMNS : public NameServerInterface {
public:
	UMNS();
	~UMNS();
	void insert(const HostName& h, const IPAddress& ip);
	bool remove(const HostName& h);
	IPAddress lookup(const HostName& h) const;
private:
	std::unordered_map<HostName,IPAddress> pairs;
};
#endif