#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T* array, std::size_t len, void (*function)(T&)) {
	if (!array || !function)
		return;
	for (size_t i = 0; i < len; i++)
		function(array[i]);
}

template <typename T>
void	iter(const T* array, std::size_t len, void (*function)(const T&)) {
	if (!array || !function)
		return;
	for (size_t i = 0; i < len; i++)
		function(array[i]);
}

#endif