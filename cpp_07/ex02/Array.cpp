#include "Array.hpp"

template <typename T>
Array<T>::Array(): _array(0), _size(0) {
	_array = new T[0];
}
template <typename T>
Array<T>::Array(unsigned int n): _array(0), _size(n) {
	_array = new T[_size];
	for (unsigned int i = 0; i < n; i++) {
		_array[i] = 0;
	}
}
template<typename T>
Array<T>::~Array(void) {
	if (!_array)
		return;
	delete [] _array;
	_array = 0;
}

template<typename T>
Array<T>::Array(Array const &toCopy): _array(0), _size(toCopy._size) {
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = toCopy._array[i];
	}
}
template<typename T>
Array<T> &Array<T>::operator=(Array const &toCopy) {
	if (this == &toCopy)
		return *this;

	_size = toCopy._size;
	delete _array;
	_array = 0;

	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = toCopy._array[i];
	}
	return *this;
}
template<typename T>
T &Array<T>::operator[](unsigned int i) {
	if (i >= _size)
		throw Array<T>::OutOfBonds();
	return _array[i];
}

template<typename T>
unsigned int	Array<T>::size(void) const {
	return _size;
}

template<typename T>
const char* Array<T>::OutOfBonds::what() const throw() {
	return "Exception : out of bonds\n";
}
