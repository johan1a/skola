#ifndef VNS_H
#define VNS_H
#include "nameserverinterface.h"
#include <string>
#include <vector>

class VNS : public NameServerInterface {
public:
	VNS();
	~VNS();
	void insert(const HostName& h, const IPAddress& ip);
	bool remove(const HostName& h);
	IPAddress lookup(const HostName& h) const;
private:
	std::vector<std::pair<HostName,IPAddress> > pairs;
};
#endif