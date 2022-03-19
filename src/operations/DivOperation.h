#pragma once

#include "operations/OperationType.h"
#include "operations/BaseOperation.h"

class DivOperation : public BaseOperation
{
public:
	using BaseOperation::BaseOperation;

private:
	OperationType operationType() const { return OperationType::DIV; };

	std::int64_t calculate() const {
		if (_rightTerm == 0) {
			throw std::out_of_range("the result is undefined because divisor is 0");
		}
		else if (_leftTerm % _rightTerm != 0) {
			throw std::out_of_range("the result is not an integer");
		}

		return _leftTerm / _rightTerm;
	}
};