
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
	// ��ġ C ������ �迭 ó�� {} �� ���� �迭�� ������ �� �ִ�.
	// {} ������ 16 - 1 ������ �ڼ��� �ٷ�Ƿ� ���⼭�� �׳� �̷���
	// ���� �Ǵ±��� �ϰ� �����ϰ� �Ѿ�� �˴ϴ�.
	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	// int arr[5] = {1, 2, 3, 4, 5}; �� ����

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

template <typename T>
struct Compare {
	bool operator()(const T& a, const T& b) { return a < b; }
};

template <typename T, typename Comp = Compare<T>>
T Min(T a, T b) {
	Comp comp;
	if (comp(a, b)) {
		return a;
	}
	else {
		return b;
	}
}
int min_main() {
	int a = 3, b = 5;
	std::cout << "Min " << a << " , " << b << " :: " << Min(a, b) << std::endl;

	std::string s1 = "abc", s2 = "def";
	std::cout << "Min " << s1 << " , " << s2 << " :: " << Min(s1, s2)
		<< std::endl;

	return 0;
}
int main()
{
	non_type_template();
	array_main();
	print_array_main();
	min_main();
	return 0;
}