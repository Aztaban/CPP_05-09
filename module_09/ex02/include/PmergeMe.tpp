template <typename Container>
void	PmergeMe::printSequence(const Container& sequence) const {
	typename Container::const_iterator	it = sequence.begin();
	typename Container::const_iterator	end = sequence.end();

	while (it < end) {
		std::cout << *it;
		it++;
		if (it != end)
			std::cout << " ";
	}
	std::cout << std::endl;
}