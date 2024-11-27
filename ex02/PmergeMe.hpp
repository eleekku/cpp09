#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>

class PmergeMe {
	private:

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void	mergeSort(std::vector<double>::iterator begin, std::vector<double>::iterator end, std::vector<double>& temp);
		void	merge(std::vector<double>::iterator left_begin, std::vector<double>::iterator right_begin, std::vector<double>::iterator left_end, std::vector<double>::iterator right_end, std::vector<double>& temp);

		void mergeque(std::deque<double>::iterator left_begin, std::deque<double>::iterator right_begin, std::deque<double>::iterator left_end, std::deque<double>::iterator right_end, std::deque<double>& temp);
		void mergeSortque(std::deque<double>::iterator begin, std::deque<double>::iterator end, std::deque<double>& temp);
};