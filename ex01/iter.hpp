#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <sstream>
#include <string>

typedef std::string string;
typedef std::ostringstream OStringStream;

template <typename T, typename F>
void iter(T *array, const std::size_t length, F function)
{
	if (!array || !function)
		return;
	for (std::size_t index = 0; index < length; ++index)
		function(array[index]);
}

template <typename T>
string ToString(const T &value)
{
	OStringStream stream;
	stream << value;
	return stream.str();
}

inline void WriteLine(const string &line)
{
	std::cout << line << std::endl;
}

#endif