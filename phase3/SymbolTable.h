#pragma once
#include <unordered_map>
#include <unordered_set>

using namespace std;

class SymbolTable {
	public:
	SymbolTable() {
		
	}
	bool contains(string s) {
		auto it = symbols.find(s);
		if (it == symbols.end()) {
			return false;
		} else {
			return true;
		}
	}
	void add(string s) {
		symbols.insert(s);
	}
	private:
	unordered_set<string> symbols;
};
