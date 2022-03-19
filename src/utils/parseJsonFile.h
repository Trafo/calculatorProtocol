#pragma once

#include "operations/VariantOperation.h"
#include "nlohmann/json.hpp"

auto parseJsonFile = [](const std::filesystem::path& path) -> std::vector<VariantOperation> {
	std::ifstream inputStream(path);
	nlohmann::json json;
	inputStream >> json;

	if (!json.contains("tasks")) {
		throw std::runtime_error("not valid JSON input format");
	}

	std::vector<VariantOperation> result;

	auto taskArray = json["tasks"];
	for (const auto& elem : taskArray) {
		if (!elem.contains("type") || !elem.contains("num1") || !elem.contains("num2")) {
			result.push_back(InvalidOperation());
		}

		try {
			result.push_back(
				createVariantOperation(
					fromString(elem["type"].get<std::string>()),
					elem["num1"].get<std::int64_t>(),
					elem["num2"].get<std::int64_t>()
				)
			);
		}
		catch (...) {
			result.push_back(InvalidOperation());
		}
	}

	return result;
};