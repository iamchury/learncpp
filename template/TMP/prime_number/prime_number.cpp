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

template <int N>
struct INT {
	static const int num = N;
};

template <typename a, typename b>
struct add {
	typedef INT<a::num + b::num> result_type; // add의 result는 타입이다. 
};

template <typename a, typename b>
struct divide {
	typedef INT<a::num / b::num> result_type; // divide의 result는 타입이다. 
};

using one = INT<1>;
using two = INT<2>;
using three = INT<3>;

template <typename N, typename d> 
struct check_div {
	//result 중에서 한개라도 true이면 전체가 true
	// check_div의 result는 bool 타입의 값이다. 
	static const bool result = (N::num % d::num == 0) ||
		check_div<N, typename add<d, one>::result_type>::result;

	// typename add<d,one>::result 에서 result는 특정값이 아니라, class type이라는 것을 compile에게 
	// 명확하게 지시하기 위해서 typename 을 붙여준다. typename 이 없으면 값으로 해석한다. 
};

template <typename N>
struct _is_prime {
	static const bool result = !check_div<N, two>::result;
};
template <>
struct _is_prime<two> {
	static const bool result = true;
};
template <>
struct _is_prime<three> {
	static const bool result = true;
};

template <typename N>
struct check_div<N, typename divide<N, two>::result_type> {
	static const bool result = (N::num % (N::num / 2) == 0);
};

template <int N>
struct is_prime {
	static const bool result = _is_prime<INT<N>>::result;
};

int main()
{
	std::cout << std::boolalpha;
	std::cout << "Is prime ? :: " << is_prime<2>::result << std::endl; // true
	std::cout << "Is prime ? :: " << is_prime<10>::result << std::endl; // false
	std::cout << "Is prime ? :: " << is_prime<11>::result << std::endl; // true
	std::cout << "Is prime ? :: " << is_prime<61>::result << std::endl; // true

	std::cout << "type one: " << one::num << std::endl;
	std::cout << "add class: " << add<one,three>::result_type::num << std::endl;
}
#endif
