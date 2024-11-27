#include "PmergeMe.hpp"
#include <chrono>


bool isValidNumber(const char* str) {
    bool hasDecimal = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!std::isdigit(str[i])) {
            if (str[i] == '.' && !hasDecimal) {
                hasDecimal = true;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "usage: " << argv[0] << " <int> [...]" << std::endl;
		return 1;
	}
	
	std::vector<double> array;
	std::vector<double> temp;
	for (int i = 1; i < argc; i++){
		if (!isValidNumber(argv[i])) {
            std::cerr << "Error: Invalid input '" << argv[i] << "'" << std::endl;
            return 1;
        }
        double num = std::strtod(argv[i], nullptr);
        if (num < 0 || num > 1000) {
            std::cerr << "Error: Number '" << argv[i] << "' is out of range (0-1000)" << std::endl;
            return 1;
        }
		array.push_back(num);
	}
	std::cout << "Before: ";
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
	PmergeMe sorter;
	auto start = std::chrono::high_resolution_clock::now();
	sorter.mergeSort(array.begin(), array.end(), temp);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> duration = end - start;

	std::cout << "After: ";
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << array.size() << " elements with std::vector: " << duration.count() << " us" << std::endl;

	std::deque<double> arrayque;
	std::deque<double> tempque;
	for (int i = 1; i < argc; i++){
		arrayque.push_back(atoi(argv[i]));
	}
	start = std::chrono::high_resolution_clock::now();
	sorter.mergeSortque(arrayque.begin(), arrayque.end(), tempque);
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << "Time to process a range of " << arrayque.size() << " elements with std::deque: " << duration.count() << " us" << std::endl;
	
};