#include <iostream>

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
	//Dim<1, 1, -2> d_num; // error. Dim< 안에 class type 이 들어가야 한다. 
	Dim<Tint<1>, Tint<2>, Tint<3>> d_num;  // Dim< > 안에 타입(class나 int, struct 등등)이 들어가서 ok. 

	std::cout << "unit cal" << std::endl;
	std::cout << "size of d_int : " << sizeof(d_int) << std::endl; // 1 
	//int sz = size_of(d_int.type); // error, d_int has no member.  type is not a member of d_int. 
	std::cout << "size of type : " << sizeof(Dim<int, int, int>::type) << std::endl;
	std::cout << "size of d_IS : " << sizeof(d_IS) << std::endl; // 1 
	std::cout << "size of char : " << sizeof(char) << std::endl; // 1 
	std::cout << "size of int : " << sizeof(int) << std::endl; // 4 
	std::cout << "size of d_num : " << sizeof(d_num) << std::endl; // 1 이것도 여전히 사이즈는 1. 

}