#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <exception>

template <typename T>
class Array
{
  private:
	T *_items;
	unsigned int _size;

  public:
	Array();
	explicit Array(unsigned int n);
	Array(const Array &other);
	~Array();

	Array &operator=(const Array &other);

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;

	unsigned int size() const;

	class IndexOutOfRangeException : public std::exception
	{
	  public:
		virtual const char *what() const throw();
	};
};

#include "Array.hpp"

#endif