#pragma once
#include <string>

class MilCode {
	public:
	MilCode() {
	
	}
	// Function Related Statements
	string param(string name) {
        return ("param " + name);
	}

	string call(string name, string dest) {
        return ("call " + name + " " + dest);
	}

	string ret(string src) {
        return ("ret" + src);
	}

	// Variable Declaration Statements
	string varName(string name) {
	    return (". " + name);
	}
	
	string arrayName(string name, string n) {
		stringstream ss;
		
	    return (".[] " + name + ", " + n);
	}

	string arrayName(string name, int n) {
		stringstream ss;
		ss << n;
		
	    return (".[] " + name + ", " + ss.str());
	}

	// Copy Statements
	string copyElement(string dst, string src) {
        return ("= " + dst + ", " + src);
	}

	// Array Access Statements
	string arrayAccessAssignFrom(string dst, string src, string index) {
	    return ("=[] " + dst + ", " + src + ", " + index);
	}

	string arrayAccessAssignTo(string dst, string index, string src) {
	    return ("[]= " + dst + ", " + index + ", " + src );
	}

	// Input/Output Statements
	string readIntoDest(string dst) {
	    return (".< " + dst);
	}

	string readIntoDestArray(string dst, string index) {
	    return (".[]< " + dst + ", " + index);
	}

	string writeSourceToOut(string src) {
	    return (".> " + src);
	}

	string writeSourceArrayToOut(string src, string index) {
	    return (".[]> " + src + ", " + index);
	}

	// Arithmetic Operator Statements (one or both source operands can be immediates)
	string arithmatic(string sign, string dst, string src1, string src2) {
	    return (sign + " " + dst + ", " + src1 + ", " + src2);
	}

	// Comparison Operator Statements (one or both source operands can be immediates)
	string comparison(string comp, string dst, string src1, string src2) {
	    return (comp + " " + dst + ", " + src1 + ", " + src2);
	}

	// Logical Operator Statements (one or both source operands can be immediates)
	string logicalBinary(string op, string dst, string src1, string src2) {
	    return (op + " " + dst + "," + src1 + ", " + src2);
	}

	string logicalNot(string dst, string src) {
	    return ("!" + dst + ", " + src);
	}

	// Label Declaration Statements
	string label(string label) {
	    return (": " + label);
	}

	// Branch Statements
	string gotoLabel(string label) {
	    return (":= " + label);
	}

	string condGotoLabel(string label, string predicate) {
	    return ("?:= " + label + ", " + predicate);
	}

	private:
	
};
