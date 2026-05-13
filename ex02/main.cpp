#include "Array.h"
#include <iostream>
#include <string>

typedef std::string string;

inline void WriteLine(const string &line)
{
	std::cout << line << std::endl;
}

int main(void)
{
	WriteLine("empty array:");
	Array<int> empty;
	WriteLine("- size = " + ToString(empty.size()));

	WriteLine("sized array (default initialized):");
	Array<int> numbers(5);
	WriteLine("- size = " + ToString(numbers.size()));
	for (unsigned int index = 0; index < numbers.size(); ++index)
		WriteLine("- numbers[" + ToString(index) + "] = " + ToString(numbers[index]));

	for (unsigned int index = 0; index < numbers.size(); ++index)
		numbers[index] = static_cast<int>(index * 10);

	WriteLine("copy constructor deep copy:");
	Array<int> copy(numbers);
	numbers[0] = 999;
	WriteLine("- numbers[0] = " + ToString(numbers[0]));
	WriteLine("- copy[0] = " + ToString(copy[0]));

	WriteLine("assignment operator deep copy:");
	Array<int> assigned;
	assigned = numbers;
	numbers[1] = 888;
	WriteLine("- numbers[1] = " + ToString(numbers[1]));
	WriteLine("- assigned[1] = " + ToString(assigned[1]));

	WriteLine("out of bounds exception:");
	try
	{
		WriteLine(ToString(numbers[42]));
	}
	catch (const std::exception &error)
	{
		WriteLine(string("- caught: ") + error.what());
	}

	WriteLine("const access:");
	const Array<int> constCopy(copy);
	WriteLine("- constCopy[2] = " + ToString(constCopy[2]));
	WriteLine("- copy[2] = " + ToString(copy[2]));

	return 0;
}
