#pragma once

#include <string>
#include <stack>
#include <iostream>
#include <sstream>

class RPNCalculator {
	private:
		std::stack<float> stack;

	public:
		RPNCalculator();
		~RPNCalculator();
		RPNCalculator(const RPNCalculator &src);
		RPNCalculator &operator=(const RPNCalculator &src);

		void push(float value);
		void add();
		void sub();
		void mul();
		void div();
		void print() const;
		void calculate(const std::string &expr);
};
