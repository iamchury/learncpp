#include <iostream>
#if 0
struct Int {
	static const int num = 12345678;
};
using IS = struct Int;

template <int N>
struct Tint {
	static const int num = N;
};

template <typename U, typename V, typename W>
struct Dim {
	using M = U;  // kg
	using L = V;  // m
	using T = W;  // s

	using type = Dim<M, L, T>;
};

int main()
{
	Dim<int, int, int> d_int;
	Dim<IS, IS, IS> d_IS;
	//Dim<1, 1, -2> d_num; // error. Dim< �ȿ� class type �� ���� �Ѵ�. 
	Dim<Tint<1>, Tint<2>, Tint<3>> d_num;  // Dim< > �ȿ� Ÿ��(class�� int, struct ���)�� ���� ok. 

	std::cout << "unit cal" << std::endl;
	std::cout << "size of d_int : " << sizeof(d_int) << std::endl; // 1 
	//int sz = size_of(d_int.type); // error, d_int has no member.  type is not a member of d_int. 
	std::cout << "size of type : " << sizeof(Dim<int, int, int>::type) << std::endl;
	std::cout << "size of d_IS : " << sizeof(d_IS) << std::endl; // 1 
	std::cout << "size of char : " << sizeof(char) << std::endl; // 1 
	std::cout << "size of int : " << sizeof(int) << std::endl; // 4 
	std::cout << "size of d_num : " << sizeof(d_num) << std::endl; // 1 �̰͵� ������ ������� 1. 

}
#else

template <int X, int Y>
struct GCD {
	static const int value = GCD<Y, X% Y>::value;
};

template <int X>
struct GCD<X, 0> {
	static const int value = X;
};

template <int N, int D = 1>
struct Ratio {
private:
	const static int _gcd = GCD<N, D>::value;

public:
	typedef Ratio<N / _gcd, D / _gcd> type;
	static const int num = N / _gcd;
	static const int den = D / _gcd;
};
template <class R1, class R2>
struct _Ratio_add {
	using type = Ratio<R1::num* R2::den + R2::num * R1::den, R1::den* R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_subtract {
	using type = Ratio<R1::num* R2::den - R2::num * R1::den, R1::den* R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_multiply {
	using type = Ratio<R1::num* R2::num, R1::den* R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide {
	using type = Ratio<R1::num* R2::den, R1::den* R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};

template <typename U, typename V, typename W>
struct Dim {
	using M = U;
	using L = V;
	using T = W;

	using type = Dim<M, L, T>;
};

#if 0
template <typename U, typename V>
struct add_dim_ {
	typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
		typename Ratio_add<typename U::L, typename V::L>::type,
		typename Ratio_add<typename U::T, typename V::T>::type>
		type;
};

template <typename U, typename V>
struct subtract_dim_ {
	typedef Dim<typename Ratio_subtract<typename U::M, typename V::M>::type,
		typename Ratio_subtract<typename U::L, typename V::L>::type,
		typename Ratio_subtract<typename U::T, typename V::T>::type>
		type;
};
#endif

template <typename T, typename D>
struct quantity {
	T q;
	using dim_type = D;

	quantity operator+(quantity<T, D> quant) {
		return quantity<T, D>(q + quant.q);
	}

	quantity operator-(quantity<T, D> quant) {
		return quantity<T, D>(q - quant.q);
	}

	quantity(T q) : q(q) {}
};
int main() {
	using one = Ratio<1, 1>;
	using zero = Ratio<0, 1>;

	quantity<double, Dim<one, zero, zero>> kg(1);
	quantity<double, Dim<zero, one, zero>> meter(1);
	quantity<double, Dim<zero, zero, one>> second(1);

	// Good
	kg + kg;

	// Bad
	// kg + meter;
	std::cout << "compile has been done successfully! " << std::endl;
}
#endif


