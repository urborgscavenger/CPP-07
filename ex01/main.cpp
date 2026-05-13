#include "iter.hpp"
#include <cctype>

template <typename T>
void PrintElement(const T &value)
{
	WriteLine("- " + ToString(value));
}

void IncrementInt(int &value)
{
	++value;
}

void ToUpperAsciiChar(char &value)
{
	value = static_cast<char>(std::toupper(static_cast<unsigned char>(value)));
}

int main(void)
{
	int numbers[] = {1, 2, 3, 4, 5};
	const std::size_t numberCount = sizeof(numbers) / sizeof(numbers[0]);

	WriteLine("numbers (initial):");
	iter(numbers, numberCount, PrintElement<int>);
	iter(numbers, numberCount, IncrementInt);
	WriteLine("numbers (incremented):");
	iter(numbers, numberCount, PrintElement<int>);

	string words[] = {"module", "cpp", "templates"};
	const std::size_t wordCount = sizeof(words) / sizeof(words[0]);
	WriteLine("words:");
	iter(words, wordCount, PrintElement<string>);

	char letters[] = {'a', 'b', 'z'};
	const std::size_t letterCount = sizeof(letters) / sizeof(letters[0]);
	iter(letters, letterCount, ToUpperAsciiChar);
	WriteLine("letters (upper):");
	iter(letters, letterCount, PrintElement<char>);

	const int fixed[] = {42, 21, 7};
	const std::size_t fixedCount = sizeof(fixed) / sizeof(fixed[0]);
	WriteLine("const fixed:");
	iter(fixed, fixedCount, PrintElement<int>);

	return 0;
}