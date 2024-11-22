#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << "usage: " << argv[0] << " <expression>" << std::endl;
		return 1;
	}

	if (argc == 2) {
		RPNCalculator calc;
		try {
			calc.calculate(argv[1]);
			calc.print();
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return 1;
		}
	}

	if (argc > 2) {
		std::string expr;
		for (int i = 1; i < argc; i++) {
			expr += argv[i];
			if (i < argc - 1) {
				expr += " ";
			}
		}
		RPNCalculator calc;
		try {
			calc.calculate(expr);
			calc.print();
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return 1;
		}
	}
	return 0;
}