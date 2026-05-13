#include <sstream>
#include <string>

// Utility converter kept in header so templates are available in all translation units.
template <typename T>
std::string ToString(const T &value)
{
	std::ostringstream stream;
	stream << value;
	return stream.str();
}

template <typename T>
Array<T>::Array() : _items(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _items(NULL), _size(n)
{
	if (_size > 0)
		_items = new T[_size]();
}

template <typename T>
Array<T>::Array(const Array &other) : _items(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _items;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return *this;
	delete[] _items;
	_size = other._size;
	_items = NULL;
	if (_size > 0)
	{
		_items = new T[_size];
		for (unsigned int index = 0; index < _size; ++index)
			_items[index] = other._items[index];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw IndexOutOfRangeException();
	return _items[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw IndexOutOfRangeException();
	return _items[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
const char *Array<T>::IndexOutOfRangeException::what() const throw()
{
	return "Array index out of range";
}
