#pragma once
#include <string>

class MilCode {
	public:
	MilCode() {
	
	}
	// Function Related Statements
	string param(string name) {
	
	}
	string call(string name, string dest) {
	
	}
	string ret(string src) {
	
	}
	// Variable Declaration Statements
	string varName(string name) {
		
	}
	string arrayName(string name) {
		
	}
	// Copy Statements
	string copyElement(string dst, string src) {
	
	}
	// Array Access Statements
	string arrayAccessAssignFrom(string dst, string src, string index) {
		
	}
	string arrayAccessAssignTo(string dst, string index, string src) {
		
	}
	// Input/Output Statements
	string readIntoDest(string dst) {
		
	}
	string readIntoDestArray(string dst, string index) {
		
	}
	string writeSourceToOut(string src) {
		
	}
	string writeSourceArrayToOut(string src, string index) {
		
	}
	// Arithmetic Operator Statements (one or both source operands can be immediates)
	string arithmatic(string sign, string dst, string src1, string src2) {
		
	}
	// Comparison Operator Statements (one or both source operands can be immediates)
	string comparison(string comp, string dst, string src1, string src2) {
		
	}
	// Logical Operator Statements (one or both source operands can be immediates)
	string logicalBinary(string op, string dst, string src1, string src2) {
		
	}
	string logicalNot(string dst, string src) {
		
	}
	// Label Declaration Statements
	string label(string label) {
		
	}
	// Branch Statements
	string gotoLabel(string label) {
		
	}
	string condGotoLabel(string label, string predicate) {
		
	}
	private:
	
};
