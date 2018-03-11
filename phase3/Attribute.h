#pragma once
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Attribute {
	public:
	Attribute() {
		name = "";
		number_val = -1;
		type = -1;
	}
	string toString() {
		stringstream ss;
		ss << "Attribute { name : \"" + name + "\" , number_val: " << number_val << " , type: " << type << " , list: ";
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
	int number_val;
	int type;
	vector<string> list;
};
