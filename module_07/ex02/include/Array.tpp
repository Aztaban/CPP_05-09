template <typename T>
Array<T>::Array(void) : _data(0), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& copy) : _data(0), _size(0) {
	*this = copy;
}

template <typename T>
Array<T>&   Array<T>::operator=(const Array& copy) {
	if (this != &copy) {
		delete[] _data;
		_size = copy._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = copy._data[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void) { delete[] _data; }

template <typename T>
T&	Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw IndexOutOfBoundsException();
	return (_data[index]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw IndexOutOfBoundsException();
	return (_data[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const {
	return (_size);
}

template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what(void) const throw() {
	return ("Index out of bounds");
}