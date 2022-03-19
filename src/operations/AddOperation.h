#pragma once

#include "operations/OperationType.h"
#include "operations/BaseOperation.h"

class AddOperation : public BaseOperation
{
public:
	using BaseOperation::BaseOperation;

private:
	OperationType operationType() const { return OperationType::ADD; };

	std::int64_t calculate() const {
		auto sum = _leftTerm + _rightTerm;

		if (_rightTerm < 0 && sum > _leftTerm) {
			throw getUnderflowError();
		}
		else if (_rightTerm > 0 && sum < _leftTerm) {
			throw getOverflowError();
		}

		return sum;
	}
};