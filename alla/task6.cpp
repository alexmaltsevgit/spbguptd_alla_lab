#include "task6.h"
#include "shared.h"

using namespace std;
using namespace shared;


namespace t6 {
	const int days_count = 5;
	const int interval_length = 3;
	const string intro_instruction = "Введите 10 цен";
	vector<int> prices{};

	void task6() {
		print_instruction(intro_instruction);
		input_many(prices, days_count);
		auto result = map_prices_to_interval(prices, interval_length);

		cout << "\nРезультат: ";
		print_vector(result);
		cout << endl;
	}


	vector<int> map_prices_to_interval(const vector<int>& prices, size_t interval_length) {
		// init
		auto left = prices.begin();
		auto right_from = [&interval_length](const vector<int>::const_iterator& left) {
			return left + interval_length; 
		};

		// set params arbitrarily
		auto slice = make_slice<int>(left, right_from(left));
		int max = calculate_max_price_increase(slice);
		auto fixed_iter = left;
		left++;

		// iterate
		for (left; right_from(left - 1) < prices.end(); left++) {
			slice = make_slice<int>(left, right_from(left));
			int local_max = calculate_max_price_increase(slice);

			if (local_max > max) {
				max = local_max;
				fixed_iter = left;
			}
		}

		// return result
		slice = make_slice<int>(fixed_iter, right_from(fixed_iter));
		return slice;
	}


	int calculate_max_price_increase(const vector<int>& interval) {
		int max = 0;

		for (
			auto right = interval.begin();
			right < interval.end(); 
			right++
		) {
			for (
				auto left = interval.begin();
				left < right;
				left++
			) {
				int diff = *right - *left;
				if (diff > max) {
					max = diff;
				}
			}
		}

		return max;
	}
}