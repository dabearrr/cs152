#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Attribute.h"

using namespace std;

class Utils {
	private:
	
	public:
	Utils() {}
	string intToString(int x) {
		stringstream ss;
		ss << x;
		return ss.str();
	}

	string charToString(char* cString) {
		string s(cString);
		return s;
	}

	void printCode(vector<string>& codeToWrite) {
		cout << "Code looks like: " << endl;
		for(int i = 0; i < codeToWrite.size(); i++) {
			cout << codeToWrite.at(i) << endl;
		}
	}
	
	void deepCopy(Attribute* a, Attribute* b) {
		a->name = b->name;
		a->type = b->type;
		a->list = b->list;
		a->number_val = b->number_val;
	}
};