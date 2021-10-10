#pragma once
#include <string>
#include <vector>

namespace t6 {
	extern const int days_count;
	extern const int interval_length;
	extern const std::string intro_instruction;
	extern std::vector<int> prices;

	void task6();

	std::vector<int> map_prices_to_interval(const std::vector<int>&, size_t);

	int calculate_max_price_increase(const std::vector<int>&);
}
