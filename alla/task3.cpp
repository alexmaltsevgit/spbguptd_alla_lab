#include "task3.h"
#include "shared.h"

using namespace shared;

namespace t3 {
	const std::string instruction =
		"Введите набор строковых значений.\nЧтобы закончить ввод, введите 0\n";

	const char sym = '*';

	std::vector<std::string> strings{};


	void task3() {
		print_instruction(instruction);
		input_until(strings, { "0" });

		if (strings.size() == 0)
			return;

		std::string max_el = find_max<std::string>(
			strings,
			compare_strings
		);

		size_t max_length = max_el.length();

		print_formatted_text(strings, sym, max_length);
	}


	void print_formatted_text(
		const std::vector<std::string>& strings,
		char decorative_sym,
		size_t max_length
	) {
		std::string full_filled_horizontal(max_length + 2, decorative_sym);

		std::cout << '\n' << full_filled_horizontal << '\n';

		for (const std::string& string : strings) {
			std::cout << decorative_sym;
			std::cout << std::left << std::setw(max_length) << string;
			std::cout << decorative_sym << '\n';
		}

		std::cout << full_filled_horizontal << '\n' << std::endl;
	}


	bool compare_strings(const std::string& right, const std::string& left) {
		return (right.length() > left.length());
	}
}
