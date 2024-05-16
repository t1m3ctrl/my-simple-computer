#include "variableTable.h"

void VariableTable::define(std::string name, int address) {
	vars[name] = address;
}

int VariableTable::get_addr(std::string name) {
	return vars[name];
}

bool VariableTable::has(std::string name) {
	return vars.find(name) != vars.end();
}