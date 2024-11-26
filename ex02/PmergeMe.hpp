#pragma once

#include <iostream>

class PmergeMe {
	private:

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void	mergeSort(std::vector<int>& array);
		void merge(std::vector<int> &array, int left, int middle, int right);


};