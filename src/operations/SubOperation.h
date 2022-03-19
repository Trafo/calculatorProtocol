#pragma once

#include "operations/OperationType.h"
#include "operations/BaseOperation.h"

class SubOperation : public BaseOperation
{
public:
	using BaseOperation::BaseOperation;

private:
	OperationType operationType() const { return OperationType::SUB; };

	std::int64_t calculate() const {
		std::int64_t difference = _leftTerm - _rightTerm;

		if ((_rightTerm < 0 && difference < _leftTerm)) {
			throw getOverflowError();
		}
		else if (_rightTerm > 0 && difference > _leftTerm) {
			throw getUnderflowError();
		}

		return difference;
	}

};