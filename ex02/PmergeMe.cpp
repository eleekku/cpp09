#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};


PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
};

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src)
		return *this;
	return *this;
};

PmergeMe::~PmergeMe() {};

void PmergeMe::mergeSort(std::vector<int>& array) {
	// Implement merge sort
	if (array.size() <= 1)
		return;
	

}

