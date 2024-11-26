#include "RPN.hpp"

RPNCalculator::RPNCalculator() {
}

RPNCalculator::~RPNCalculator() {
}

RPNCalculator::RPNCalculator(const RPNCalculator &src) {
	*this = src;
}

RPNCalculator &RPNCalculator::operator=(const RPNCalculator &src) {
	if (this != &src) {
		this->stack = src.stack;
	}
	return *this;
}

void RPNCalculator::push(float value) {
	this->stack.push(value);
}

void RPNCalculator::add() {
	if (this->stack.size() < 2) {
		throw std::runtime_error("Not enough operands");
	}
	float a = this->stack.top();
	this->stack.pop();
	float b = this->stack.top();
	this->stack.pop();
	this->stack.push(a + b);
}

void RPNCalculator::sub() {
	if (this->stack.size() < 2) {
		throw std::runtime_error("Not enough operands");
	}
	float a = this->stack.top();
	this->stack.pop();
	float b = this->stack.top();
	this->stack.pop();
	this->stack.push(b - a);
}

void RPNCalculator::mul() {
	if (this->stack.size() < 2) {
		throw std::runtime_error("Not enough operands");
	}
	float a = this->stack.top();
	this->stack.pop();
	float b = this->stack.top();
	this->stack.pop();
	this->stack.push(a * b);
}

void RPNCalculator::div() {
	if (this->stack.size() < 2) {
		throw std::runtime_error("Not enough operands");
	}
	float a = this->stack.top();
	this->stack.pop();
	float b = this->stack.top();
	this->stack.pop();
	if (a == 0) {
		throw std::runtime_error("Division by zero");
	}
	this->stack.push(b / a);
}

void RPNCalculator::print() const {
	std::stack<float> tmp = this->stack;
	while (!tmp.empty()) {
		std::cout << tmp.top() << std::endl;
		tmp.pop();
	}
}

void RPNCalculator::calculate(const std::string &expr) {
	std::istringstream iss(expr);
	std::string token;
	while (iss >> token) {
		if (token == "+") {
			this->add();
		} else if (token == "-") {
			this->sub();
		} else if (token == "*") {
			this->mul();
		} else if (token == "/") {
			this->div();
		} else {
			try {
				this->push(std::stof(token));
			} catch (std::exception &e) {
				throw std::runtime_error("Invalid token");
			}
		}
	}
}
