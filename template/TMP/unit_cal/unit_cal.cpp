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