#pragma once
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Attribute {
	public:
	Attribute() {
		name = "";
		index = "";
		number_val = -1;
		type = -1;
		sizeOfAttr = -1;
	}
	string toString() {
		stringstream ss;
		ss << "Attribute { name : \"" << name << "\" index : \"" << index << "\" , number_val: " << number_val << " , type: " << type << " , sizeOfAttr: " << sizeOfAttr << " , list: ";
		if(list.empty()) {
			ss << "empty }";
		}
		for(int i = 0; i < list.size(); i++) {
			if (i != list.size() - 1) {
				ss << "\"" << list.at(i) << "\", ";
			} else {
				ss << "\"" << list.at(i) << "\" }";
			}
		}
		
		return ss.str();
	}
	string name;
	string index;
	int number_val;
	int type;
	int sizeOfAttr;
	vector<string> list;
};
