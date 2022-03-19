#pragma once

enum class OperationType {
	UNKNOWN,
	ADD,
	SUB,
	MUL,
	DIV
};

OperationType fromString(const std::string& operationType) {
	if (operationType == "ADD")
		return OperationType::ADD;
	else if (operationType == "SUB")
		return OperationType::SUB;
	else if (operationType == "MUL")
		return OperationType::MUL;
	else if (operationType == "DIV")
		return OperationType::DIV;

	return OperationType::UNKNOWN;
}

std::string toString(OperationType operationType) {
	switch (operationType) {
	case OperationType::ADD:
		return "ADD";
	case OperationType::SUB:
		return "SUB";
	case OperationType::MUL:
		return "MUL";
	case OperationType::DIV:
		return "DIV";
	case OperationType::UNKNOWN:
		return "UNKNOWN";
	}

	return "UNKNOWN";
}