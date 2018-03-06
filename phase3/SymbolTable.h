#include <unordered_map>

using namespace std;

class SymbolTable {
	public:
	SymbolTable() {
		
	}
	bool contains(string s) {
		unordered_set::const_iterator it = symbol.find(s);
		if (it == symbol.end()) {
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
}