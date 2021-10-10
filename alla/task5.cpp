#include "task5.h"
#include "shared.h"

using namespace shared;
using namespace std;


namespace t5 {
	const string intro_instruction = "Вводите автомобильные номера.\nЧтобы закончить ввод, введите 0\n";
	const string write_region_instruction = "Введите регион, по которому произвести фильтр";

	vector<string> plate_numbers{};
	string region{};

	void task5() {
		print_instruction(intro_instruction);
		input_until(plate_numbers, { "0" });

		if (plate_numbers.size() == 0)
			return;

		print_instruction(write_region_instruction);
		cin >> region;

		auto filter_function = get_filter_function(region);

		filter_with_callback<void>(
			plate_numbers,
			filter_function,
			on_good_plate_number
		);
	}


	bool str_ends_with(const string& origin, const string& subject) {
		if (origin.length() < subject.length())
			return false;

		return origin.compare(
			origin.length() - subject.length(),
			subject.length(),
			subject
		) == 0;
	}


	std::function<bool(const string&)> get_filter_function(const string& region) {
		return [&region](const string& number) {
			return str_ends_with(number, region);
		};
	}

	void on_good_plate_number(const std::string& number) {
		cout << number << endl;
	}
}
