#include <iostream>
#include <typeinfo>

template <int X, int Y>
struct GCD {
	static const int value = GCD < Y, X% Y>::value;
};

template <int X> 
struct GCD<X, 0> {
	static const int value = X;
};

template <int N, int D=1>
struct Ratio {
private:
	const static int _gcd = GCD<N, D>::value;

public:
	typedef Ratio<N / _gcd, D / _gcd> type; // 결과값이 저장된다. 
	static const int num = N / _gcd; // Numerator
	static const int den = D / _gcd; // Denominator

};

template <class R1, class R2> 
struct _Ratio_add {
	using type = Ratio<R1::num * R2::den + R2::num*R1::den, R1::den* R2::den>;
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

class Vehicle {
public:
	std::string brand = "Ford";
	class sub_veh {
	public:
		std::string sub_brand = "F1";

		void print_sub_brand() {
			std::cout << "sub brand : " << sub_brand << std::endl;
		}
	} s;
	void honk()
	{
		std::cout << "Tuut, tuut! \n";
	}
};

// nested inheritance. 
// without public, it can't access. 
class ford : public Vehicle::sub_veh {};
class car : public Vehicle {};

int car_main()
{
	ford f;
	f.print_sub_brand();

	car c;
	c.s.print_sub_brand();
	c.honk();

	return 0;
}
int main()
{
	using r1 = Ratio<2, 3>;
	using r2 = Ratio<3, 2>;

	using r3 = Ratio_add<r1, r2>;
	std::cout << "2/3 + 3/2 = " << r3::num << " / " << r3::den << std::endl;

	using r4 = Ratio_multiply<r1, r3>;
	std::cout << "13 / 6 * 2 /3 = " << r4::num << " / " << r4::den << std::endl;

	car_main();
	return 0;
}
