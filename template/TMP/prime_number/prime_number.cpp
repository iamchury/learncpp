#include <iostream>
#include <ios>

// Template Metadata Programming (TMP)
#define TMP_USED

#ifndef TMP_USED
bool is_prime(int N)
{
	if (N == 2) return true;
	if (N == 3) return true;

	for (int i = 2; i < N / 2; i++) {
		if ((N % i) == 0) return false;
	}
	return true;
}

int main()
{
	std::cout << std::boolalpha;
	std::cout << "Is prime ? :: " << is_prime(2) << std::endl; // true
	std::cout << "Is prime ? :: " << is_prime(10) << std::endl; // false
	std::cout << "Is prime ? :: " << is_prime(11) << std::endl; // true
	std::cout << "Is prime ? :: " << is_prime(61) << std::endl; // true
}
#else
template <>
struct is_prime<2> {
	static const bool result = true;
};
template <>
struct is_prime<3> {
	static const bool result = true;
};

template <int N>
struct is_prime {
	static const bool result = !check_div<N, 2>::result;
};

template <int N, int d> 
struct check_div {
	static const bool result = (N % d == 0) || check_div<N, d + 1>::result;
};
template <int N> 
struct check_div<N, N / 2> {
	struct const bool result = (N % (N / 2) == 0);
};

int main()
{
	std::cout << std::boolalpha;
	std::cout << "Is prime ? :: " << is_prime<2>::result << std::endl; // true
	std::cout << "Is prime ? :: " << is_prime<10>::result << std::endl; // false
	std::cout << "Is prime ? :: " << is_prime<11>::result << std::endl; // true
	std::cout << "Is prime ? :: " << is_prime<61>::result << std::endl; // true
}
#endif
