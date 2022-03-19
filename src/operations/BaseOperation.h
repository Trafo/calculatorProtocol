#pragma once

#include "operations/OperationType.h"

class BaseOperation {
public:
	explicit BaseOperation(std::int64_t leftTerm, std::int64_t rightTerm)
		: _leftTerm(leftTerm)
		, _rightTerm(rightTerm)
	{}

	std::string resultAsString() const {
		return std::to_string(calculate());
	}

protected:
	virtual std::int64_t calculate() const = 0;
	virtual OperationType operationType() const = 0;

	std::overflow_error getOverflowError() const {
		return std::overflow_error("result of operation " + toString(operationType())
			+ " exceeds: " +
			std::to_string(std::numeric_limits<std::uint64_t>::max()));
	}

	std::underflow_error getUnderflowError() const {
		return std::underflow_error("result of operation " + toString(operationType())
			+ " falls short of min value: " +
			std::to_string(std::numeric_limits<std::uint64_t>::min()));
	}

	std::int64_t _leftTerm;
	std::int64_t _rightTerm;
};