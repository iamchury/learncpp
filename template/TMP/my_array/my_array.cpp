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

int main() {
	int arr[3] = { 1, 2, 3 };
	
	// Array wrapper class
	Array<int, 3> arr_w(arr);

	arr_w.print_all();
	std::cout << "Array [] operator override: Array[0]: " << arr_w[0] << std::endl;
}
