#ifndef HNS_H
#define HNS_H
#include "nameserverinterface.h"
#include <string>
#include <vector>

class HNS : public NameServerInterface {
public:
	HNS(int s);
	~HNS();
	void insert(const HostName& h, const IPAddress& ip);
	bool remove(const HostName& h);
	IPAddress lookup(const HostName& h) const;
private:
	std::vector<std::vector<std::pair<HostName,IPAddress> > > pairs;
	int hash_code(const HostName& h) const;
	int size;
};
#endif