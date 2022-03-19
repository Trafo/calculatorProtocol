#include <iostream>
#include <fstream>
#include <filesystem>
#include <variant>

#include "nlohmann/json.hpp"

#include "operations/VariantOperation.h"
#include "utils/parseJsonFile.h"

auto getPathFromUser = []() {
	while (true) {
		std::string input;

		std::cout << "path of JSON file: ";
		std::cin >> input;
		try {
			auto jsonTaskPath = std::filesystem::path(input);
			if (!std::filesystem::exists(jsonTaskPath)) {
				std::cout << "JSON file could not be found" << std::endl;
				continue;
			}
			return jsonTaskPath;
		}
		catch (...) {
			std::cout << "error: is not a filesystem path" << std::endl;
			continue;
		}
	};
};

std::string getResultString(const VariantOperation& op) {
	try {
		return std::visit([](const auto& obj) -> std::string { return obj.resultAsString(); }, op);
	}
	catch (...) {
		return "Invalid";
	}
};


int main(int argc, char* argv[])
{
	// C:/Projekte/calculatorProtocol/tasks.json
	auto jsonTaskPath = getPathFromUser();

	auto tasks = parseJsonFile(jsonTaskPath);

	std::string resultString = "";
	for (const auto& task : tasks) {
		resultString += getResultString(task) + ", ";
	}

	// remove trailing comma
	if (resultString.length() >= 2) {
		resultString.pop_back();
		resultString.pop_back();
	}

	std::cout << resultString << std::endl;

	return 0;
}