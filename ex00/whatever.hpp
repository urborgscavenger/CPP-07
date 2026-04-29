#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <sstream>
#include <string>

typedef std::string string;
typedef std::ostringstream OStringStream;

template <typename T>
void swap(T &first, T &second)
{
	T temp = first;
	first = second;
	second = temp;
}

template <typename T>
const T &min(const T &first, const T &second)
{
	if (first < second)
		return first;
	return second;
}

template <typename T>
const T &max(const T &first, const T &second)
{
	if (first > second)
		return first;
	return second;
}

template <typename T>
string ToString(const T &value)
{
	OStringStream stream;
	stream << value;
	return stream.str();
}

#endif