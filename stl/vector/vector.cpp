#include <iostream>
#include <vector>

void vec_ex1() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
	std::cout << "vec 의 " << i + 1 << " 번째 원소 :: " << vec[i] << std::endl;
	}
}

void vec_ex2() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end();++itr) {
		std::cout << *itr << std::endl;
	}

	// int arr[4] = {10, 20, 30, 40}
	// *(arr + 2) == arr[2] == 30;
	// *(arr + 2)  == vec[2] == 30; 

	std::vector<int>::iterator itr = vec.begin() + 2;
	std::cout << "3 번째 원소 :: " << *itr << std::endl;
}

template <typename T>
void print_vector(std::vector<T>& vec) {
	std::cout << "[ ";
	for (typename std::vector<T>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << "]";
}

void vec_ex3()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::cout << "처음 벡터 상태" << std::endl;
	print_vector(vec);
	std::cout << "----------------------------" << std::endl;

	// vec[2] 앞에 15 추가
	vec.insert(vec.begin() + 2, 15);
	print_vector(vec);

	std::cout << "----------------------------" << std::endl;
	// vec[3] 제거
	vec.erase(vec.begin() + 3);
	print_vector(vec);
}
void vec_ex4()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::cout << "처음 벡터 상태" << std::endl;
	print_vector(vec);
	std::cout << "----------------------------" << std::endl;

	std::vector<int>::iterator itr = vec.begin();
	//std::vector<int>::iterator end_itr = vec.end();

	for (; itr != vec.end(); ++itr) {  // runtime error will happen. ++itr tried to increase past end. 
		if (*itr == 20) {
			vec.erase(itr); // after earse an element, vec_end() is updated. 
			itr = vec.begin();
		}
	}

	std::cout << "값이 20인 원소들을 지운다" << std::endl;
	std::cout << "----------------------------" << std::endl;

}

int main()
{
	vec_ex1();
	vec_ex2();
	vec_ex3();
	vec_ex4();

	return 1;
}