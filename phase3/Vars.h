 #pragma once
 #include <string>
 #include <sstream>

using namespace std;
 
 class Vars {
	public:
	Vars() {
		counter = 1;
		labelCounter = 1;
	}
	string getTemp() {
		return "__temp__" + intToString(counter);
		counter++;
	}
	string getLabel() {
		return "__label__" + intToString(labelCounter);
		labelCounter++;
	}
	private:
	int counter;
	int labelCounter;
	
	string intToString(int x) {
		stringstream ss;
		ss << x;
		return ss.str();
	}
 };