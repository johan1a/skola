#ifndef MNS_H
#define MNS_H
#include "nameserverinterface.h"
#include <string>
#include <map>
class MNS : public NameServerInterface {
public:
	MNS();
	~MNS();
	void insert(const HostName& h, const IPAddress& ip);
	bool remove(const HostName& h);
	IPAddress lookup(const HostName& h) const;
private:
	std::map<HostName,IPAddress> pairs;
};
#endif