
#include <iostream>

template <typename T, int num>
T add_num(T t) {
	return t + num;
}

int non_type_template() {
	int x = 3;
	std::cout << "x : " << add_num<int, 5>(x) << std::endl;
	return 0;
}

// array example
#include <array>

int array_main() {
	// 마치 C 에서의 배열 처럼 {} 을 통해 배열을 정의할 수 있다.
	// {} 문법은 16 - 1 강에서 자세히 다루므로 여기서는 그냥 이렇게
	// 쓰면 되는구나 하고 이해하고 넘어가면 됩니다.
	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	// int arr[5] = {1, 2, 3, 4, 5}; 와 동일

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

#if 0
void print_array(const std::array<int, 5>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int print_array_main() {
	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };

	print_array(arr);
	return 0;
}
#else
template <typename T>
void print_array(const T& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
int print_array_main() {
	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	std::array<int, 7> arr2 = { 1, 2, 3, 4, 5, 6, 7 };
	std::array<int, 3> arr3 = { 1, 2, 3 };

	print_array(arr);
	print_array(arr2);
	print_array(arr3);

	return 0;
}
#endif

int main()
{
	non_type_template();
	array_main();
	print_array_main();

	return 0;
}