#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <stdexcept>
#include <exception>
#include <string>
#include <cstdlib> 
#include <iostream>
#include <algorithm>

class PMergeMe
{
	public:
	PMergeMe();
	PMergeMe(const PMergeMe &src);
	PMergeMe& operator = (const PMergeMe &src);
	~PMergeMe();

	void checkInput(int ac, char **av);
	void sortInput(int ac, char **av);
	
	
	private:
	std::deque<int> _deque;
	std::vector<int> _vector;

	int _oddNb;
	size_t _size;

	int isSortedVec() const;
	int isSortedDeq() const;
	int hasDouble() const;
	
	//vectors
	void _sortVector();
	void _makePairsVec(std::vector<int> &vbig, std::vector<int> &vsmall);
	void _mergeSortVec(std::vector<int> &vbig, std::vector<int> &vsmall);
	void _dichotomyInsert(int &high, int &low, unsigned int &mid, unsigned int &index, std::vector<int> &vsmall);
	
	//deque
	void _sortDeque();
	void _makePairsDeque(std::deque<int> &vbig, std::deque<int> &vsmall);
	void _mergeSortDeque(std::deque<int> &vbig, std::deque<int> &vsmall);
	void _dichotomyInsertDeque(int &high, int &low, unsigned int &mid, unsigned int &index, std::deque<int> &vsmall);
};

#endif