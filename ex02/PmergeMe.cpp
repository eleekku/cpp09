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

void PmergeMe::merge(std::vector<double>::iterator left_begin, std::vector<double>::iterator right_begin, std::vector<double>::iterator left_end, std::vector<double>::iterator right_end, std::vector<double>& temp) {
	temp.clear();
	temp.reserve(std::distance(left_begin, left_end) + std::distance(right_begin, right_end));

	auto l = left_begin;
	auto r = right_begin;

	while (l < left_end && r < right_end) {
		if (*l < *r) {
			temp.push_back(*l);
			l++;
		}
		else {
			temp.push_back(*r);
			r++;
		}
	}
	
	temp.insert(temp.end(), l, left_end);
	temp.insert(temp.end(), r, right_end);
	std::copy(temp.begin(), temp.end(), left_begin);
}

void PmergeMe::mergeSort(std::vector<double>::iterator begin, std::vector<double>::iterator end, std::vector<double>& temp) {
	if (std::distance(begin, end) <= 1)
		return;
	
	auto middle = begin + std::distance(begin, end) / 2;
    mergeSort(begin, middle, temp);
    mergeSort(middle, end, temp);
	merge(begin, middle, middle, end, temp);
}

void PmergeMe::mergeque(std::deque<double>::iterator left_begin, std::deque<double>::iterator right_begin, std::deque<double>::iterator left_end, std::deque<double>::iterator right_end, std::deque<double>& temp) {
    temp.clear();

    auto l = left_begin;
    auto r = right_begin;

    while (l < left_end && r < right_end) {
        if (*l < *r) {
            temp.push_back(*l);
            l++;
        } else {
            temp.push_back(*r);
            r++;
        }
    }

    temp.insert(temp.end(), l, left_end);
    temp.insert(temp.end(), r, right_end);

    std::copy(temp.begin(), temp.end(), left_begin);
}

void PmergeMe::mergeSortque(std::deque<double>::iterator begin, std::deque<double>::iterator end, std::deque<double>& temp) {
    if (std::distance(begin, end) <= 1)
        return;

    auto middle = begin + std::distance(begin, end) / 2;
    mergeSortque(begin, middle, temp);
    mergeSortque(middle, end, temp);
    mergeque(begin, middle, middle, end, temp);
}

