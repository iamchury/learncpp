#include <iostream>

#if 1
template <typename T>
void print(T arg) {
	std::cout << arg << std::endl;
}
#else
void print() {
	std::cout << std::endl;
	std::cout << "last called" << std::endl;
}
#endif

template <typename T, typename... Types>
void print(T arg, Types... args) {
	std::cout << arg << ", ";
	print(args...);
}

int main()
{
	print(1, 3.1, "abc");
	print(1, 2, 3, 4, 5, 6, 7);

	return 0;
}