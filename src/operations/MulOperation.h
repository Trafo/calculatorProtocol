#pragma once

#include "operations/OperationType.h"
#include "operations/BaseOperation.h"

class MulOperation : public BaseOperation
{
public:
	using BaseOperation::BaseOperation;

private:
	OperationType operationType() const { return OperationType::MUL; };

	std::int64_t calculate() const {
		if (((_leftTerm > 0 && _rightTerm > 0) || (_leftTerm < 0 && _rightTerm < 0)) &&
			(std::llabs(std::numeric_limits<std::uint64_t>::max() / _rightTerm) < std::llabs(_leftTerm))) {
			throw getOverflowError();
		}
		else if (((_leftTerm > 0 && _rightTerm < 0) || (_leftTerm < 0 && _rightTerm > 0)) &&
			(std::llabs(std::numeric_limits<std::uint64_t>::min() / _rightTerm) < std::llabs(_leftTerm))) {
			std::cout << std::llabs(std::numeric_limits<std::uint64_t>::max() / _rightTerm) << " " << std::llabs(_leftTerm) << std::endl;
			throw getUnderflowError();
		}

		return _leftTerm * _rightTerm;
	}
};