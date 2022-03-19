#pragma once

#include <variant>

#include "operations/AddOperation.h"
#include "operations/SubOperation.h"
#include "operations/MulOperation.h"
#include "operations/DivOperation.h"
#include "operations/InvalidOperation.h"

using VariantOperation = std::variant<InvalidOperation,
	AddOperation,
	SubOperation,
	MulOperation,
	DivOperation>;

auto createVariantOperation = [](OperationType type, std::int64_t leftTerm, std::int64_t rightTerm) -> VariantOperation {
	switch (type) {
	case OperationType::ADD:
		return AddOperation(leftTerm, rightTerm);
	case OperationType::SUB:
		return SubOperation(leftTerm, rightTerm);
	case OperationType::MUL:
		return MulOperation(leftTerm, rightTerm);
	case OperationType::DIV:
		return DivOperation(leftTerm, rightTerm);
	case OperationType::UNKNOWN:
		return InvalidOperation();
	}

	return InvalidOperation();
};