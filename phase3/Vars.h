 #pragma once
 #include <string>
 #include <sstream>

using namespace std;
 
 class Vars {
	public:
	Vars() {
		counter = 1;
	}
	string getTemp() {
		return "__temp__" + intToString(counter);
		counter++;
	}
	private:
	int counter;
	
	string intToString(int x) {
		stringstream ss;
		ss << x;
		return ss.str();
	}
 };