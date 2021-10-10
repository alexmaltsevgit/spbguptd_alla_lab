#include "task7.h"
#include "shared.h"
#include <stack>

using namespace std;
using namespace shared;

namespace t7 {
	const std::string intro_instruction = "Введите целое число\n";

	void task7() {
		print_instruction(intro_instruction);
		int value = input_once<int>();
		stack<uint16_t> binary = to_binary(value);
		print_stack(binary);
		cout << '\n';
	}


	stack<uint16_t> to_binary(unsigned int number, stack<uint16_t>* buffer) {
		buffer = (buffer) ? buffer : new stack<uint16_t>{};

		buffer->push(number % 2);
		unsigned int half = number / 2;

		if (half != 0) {
			to_binary(half, buffer);
		}

		return *buffer;
	}
}