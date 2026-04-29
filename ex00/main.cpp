#include "whatever.hpp"

inline void WriteLine(const string &line)
{
	std::cout << line << std::endl;
}

int main(void)
{
	int a = 2;
	int b = 3;

	::swap(a, b);
	WriteLine("a = " + ToString(a) + ", b = " + ToString(b));
	WriteLine("min(a, b) = " + ToString(::min(a, b)));
	WriteLine("max(a, b) = " + ToString(::max(a, b)));

	string c = "chaine1";
	string d = "chaine2";

	::swap(c, d);
	WriteLine("c = " + c + ", d = " + d);
	WriteLine("min(c, d) = " + ::min(c, d));
	WriteLine("max(c, d) = " + ::max(c, d));
	return 0;
}