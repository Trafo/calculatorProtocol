#pragma once

#include "operations/OperationType.h"
#include "operations/BaseOperation.h"

class InvalidOperation : public BaseOperation
{
public:
	InvalidOperation() : BaseOperation(0, 0) {};

private:
	OperationType operationType() const { return OperationType::UNKNOWN; };

	std::int64_t calculate() const {
		throw std::invalid_argument("unknown operation");
	}
};