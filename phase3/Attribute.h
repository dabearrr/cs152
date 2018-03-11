#pragma once
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Attribute {
	public:
	Attribute() {
		name = "";
		size = 0;
		type = -1;
	}
	string toString() {
		stringstream ss;
		ss << "Attribute { name : \"" + name + "\" , size: " << size << " , type: " << type << " , list: ";
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
	int size;
	int type;
	vector<string> list;
};
