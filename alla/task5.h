#pragma once
#include <string>
#include <vector>
#include <functional>

// Напишите программу, которая принимает на вход список номеров автомобилей в формате "А000АА77" (где 77 - регион),
// и выводит на экран все номера из указанного пользователем региона
namespace t5 {
	extern const std::string intro_instruction;
	extern const std::string write_region_instruction;
	extern std::vector<std::string> plate_numbers;
	extern std::string region;

	void task5();


	template<typename callback_output_t>
	void filter_with_callback(
		std::vector<std::string> container,
		std::function<bool(const std::string&)> predicat,
		std::function<callback_output_t(const std::string&)> callback
	) {
		for (const auto& el : container) {
			if (predicat(el)) {
				callback(el);
			}
		}
	};


	bool str_ends_with(const std::string& origin, const std::string& subject);


	std::function<bool(const std::string&)> get_filter_function(const std::string& region);


	void on_good_plate_number(const std::string&);
}
