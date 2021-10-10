#pragma once
#include <vector>
#include <stack>
#include <string>
#include <iostream>


namespace shared {
	using namespace std;


	void print_instruction(const string& instruction);


	template<typename T>
	vector<T> make_slice(
		const typename vector<T>::const_iterator& begin, 
		const typename vector<T>::const_iterator& end
	) {
		vector<T> vec = { begin, end };
		return vec;
	}


	template<typename T>
	void input_until(
		vector<T>& container,
		const T& termination_sym
	) {
		T another_one{};
		while (true) {
			cin >> another_one;
			if (another_one != termination_sym) {
				container.push_back(another_one);
			} else {
				return;
			}
		}
	}


	template<typename T>
	T input_once() {
		T value{};
		cin >> value;
		
		return value;
	}


	template<typename T>
	void input_many(vector<T>& container, size_t n_times) {
		T another_one{};
		for (size_t i = 0; i < n_times; i++) {
			cin >> another_one;
			container.push_back(another_one);
		}
	}


	template<typename T>
	void print_vector(const vector<T>& vec) {
		cout << '[';
		for (size_t i = 0; i < vec.size(); i++) {
			cout << vec[i];
			if (i != vec.size() - 1) {
				cout << ", ";
			} else {
				cout << ']';
			}
		}
	}


	template<typename T>
	void print_stack(stack<T>& st) {
		cout << '[';
		while (!st.empty()) {
			cout << st.top();
			if (st.size() != 1) {
				cout << ", ";
			} else {
				cout << ']';
			}
			st.pop();
		}
	}
}