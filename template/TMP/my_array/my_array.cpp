/* My arrary implement. std::array */ 
#include <iostream>

template <typename T, unsigned int N>
class Array {
	T data[N];

public:
	// an reference arr of array.
	Array(T(&arr)[N]) {
		for (int i = 0; i < N; i++) {
			data[i] = arr[i];
		}
	}

	T* get_array() { return data; }

	unsigned int size() { return N; }

	void print_all() {
		for (int i = 0; i < N; i++) {
			std::cout << data[i] << ", ";
		}
		std::cout << std::endl;
	}
	
	T operator[](const int index) {
		return data[index];
	}
};

int Array_main() {
	int arr[3] = { 1, 2, 3 };
	
	// Array wrapper class
	Array<int, 3> arr_w(arr);

	arr_w.print_all();
	std::cout << "Array [] operator override: Array[0]: " << arr_w[0] << std::endl;

	return 0;
}

#include <typeinfo>
template <int N>
struct Int {
	static const int num = N;
};

template <typename T, typename U>
struct add {
	typedef Int<T::num + U::num> result; // 여기에는 먼저 Int<T + U>를 한 결과 값 num 이 
	// static const int 타입으로 생성되고, 그리고 그 값이 typedef를 통해 result로 alias된다.
};

int int_add_main()
{
	typedef Int<1> one; // Int num=1로 클라스를 생성하고(객체를 생성하는 것은 아님) one으로 alias.
	typedef Int<2> two;

	typedef add<one, two>::result three; // add<one, two>로 된 class를 생성하고, 멤버인 result를 
	// three 로 alias 한다. 즉 컴파일러가 클라스를 생성하고, 그 멤버의 값을 alias 시킨다. 

	std::cout << "Addition result : " << three::num << std::endl;
	
	return 0;
}

template <int N>
struct Factorial {
	static const int result = N * Factorial<N - 1>::result;
};

template <>
struct Factorial<1> {
	static const int result = 1;
};

int factorial_main()
{
	std::cout << "6! = 6*5*4*3*2*1 = " << Factorial<6>::result << std::endl;

	return 0;
}

template <int B, int S>
struct GCD {
	static const int value = GCD<S, B% S>::value;
};

template <>
struct GCD<36, 24> {
	//std::cout << "GCD 24, 128" << std::endl;
	// it's wrong value. just for test. this specialization will be called. 
	static const int value = 100;
};

template <int B >
struct GCD<B, 0> {
	static const int value = B;
};

int gcd_main()
{
	std::cout << "gcd (36, 24) :: " << GCD<36, 24>::value << std::endl;
	std::cout << "gcd (256, 96) :: " << GCD<256, 96>::value << std::endl;
	return 0;
}

int main()
{
	Array_main();
	int_add_main();
	factorial_main();
	gcd_main();

	return 0;
}
