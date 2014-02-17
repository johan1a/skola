#ifndef TAGREMOVER_H
#define TAGREMOVER_H
#include <string>
#include <vector>
#include <ostream>
#include <istream>

class TagRemover{
public:
	TagRemover(std::istream& in);
	void print(std::ostream& out);
private:
	std::vector<std::string> content;
	void replace(std::string& s,const std::string& from, const std::string& to);
	void parse();
};
#endif