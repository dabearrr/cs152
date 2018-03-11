#pragma once
#include <iostream>
#include <string>
#include <vector>

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
};