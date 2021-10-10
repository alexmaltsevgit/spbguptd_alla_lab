#pragma once
#include <string>
#include <stack>

namespace t7 {
	extern const std::string intro_instruction;

	void task7();

	std::stack<uint16_t> to_binary(unsigned int number, std::stack<uint16_t>* = nullptr);
}
