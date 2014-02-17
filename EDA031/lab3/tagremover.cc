#include <iostream>
#include "tagremover.h"
using namespace std;

TagRemover::TagRemover(istream& in){
	string line, line_to_save;
	bool inside_tag = false;
	while(!in.eof()){
		line_to_save = "";
		char c;
		getline(in,line);
		for(size_t i = 0; i < line.size();i++){
			c = line.at(i);
			if(c == '<'){
				inside_tag = true;
			}else if (c == '>'){
				inside_tag = false;
			}else if(!inside_tag){
				int size = line_to_save.size();
				if(c == ' ' && (size == 0 || line_to_save.at(size-1) == ' ')){
					continue;
				}
				line_to_save = line_to_save + c;
			}
		}
		if(line_to_save.size() > 0){
			replace(line_to_save,"&lt;","<");
			replace(line_to_save,"&gt;",">");
			replace(line_to_save,"&nbsp;", " ");
			replace(line_to_save,"&amp;","&");
			content.push_back(line_to_save);
		}
	}
}

void TagRemover::replace(string& s,const string& from, const string& to){
	size_t pos = s.find(from);
	while(pos != string::npos){
		s.replace(pos, from.size(), to);
		pos = s.find(from);
	}
}

void TagRemover::print(ostream& out){
	for(size_t i = 0; i < content.size();i++){
		out << content[i] << endl;
	}
}