#pragma once
#include <string>
#include <vector>
#include <functional>
#include <iomanip>


// Напишите программу, которая принимает набор строковых значений у пользователя, а затем выводит их в консоль в
// рамочке из любого символа, например:
// ***********
// * Гаррош *
// * не *
// * виноват *
// * ! *
// ***********
namespace t3 {
	extern const std::string instruction;
	extern const char sym;
	extern std::vector<std::string> strings;

	void task3();


	template<typename T>
	T find_max(
		const std::vector<T>& container,
		const std::function<bool(const T&, const T&)> predicat
	) {
		// edge case
		if (container.size() == 0) {
			return T{};
		}

		T max = container[0];

		// edge case
		if (container.size() == 1) {
			return max;
		}

		// start iteration from second element
		auto iter = container.begin();
		iter++;
		for (iter; iter != container.end(); iter++) {
			auto left = *(iter - 1);
			auto right = *iter;
			if (predicat(left, right)) {
				max = right;
			}
		}

		return max;
	}


	void print_formatted_text(
		const std::vector<std::string>& strings,
		char decorative_sym,
		size_t max_length
	);


	bool compare_strings(const std::string& left, const std::string& right);
}
