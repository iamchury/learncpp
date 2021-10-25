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
	std::cout << "]" << std::endl;
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

	std::cout << std::endl;
	std::cout << "처음 벡터 상태" << std::endl;
	print_vector(vec);
	std::cout << "----------------------------" << std::endl;

	for (unsigned int i = 0; i < vec.size(); i++)
	{
		std::vector<int>::iterator iter = vec.begin() + i;
		if (*iter == 20)
		{
			vec.erase(vec.begin() + i);
			i--;
		}
	}

	std::cout << "값이 20인 원소들을 지운다" << std::endl;
	std::cout << "----------------------------" << std::endl;
	print_vector(vec);
}

void vec_ex5(){
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::cout << "초기 vec 상태" << std::endl;
	print_vector(vec);

	// itr 은 vec[2] 를 가리킨다.
	std::vector<int>::iterator itr = vec.begin() + 2;

	// vec[2] 의 값을 50으로 바꾼다.
	*itr = 50;

	std::cout << "---------------" << std::endl;
	print_vector(vec);

	std::vector<int>::const_iterator citr = vec.cbegin() + 2;

	// 상수 반복자가 가리키는 값은 바꿀수 없다. 불가능!
	// *citr = 30;  // compile error.
}

void vec_ex6() {
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::cout << "초기 vec 상태" << std::endl;
	print_vector(vec);

	std::cout << "역으로 vec 출력하기!" << std::endl;
	std::cout << "[ ";
	for (std::vector<int>::reverse_iterator r_iter = vec.rbegin(); r_iter != vec.rend(); ++r_iter) {
		std::cout << *r_iter << " ";
	}
	std::cout << "] " << std::endl;

}
#include <typeinfo>

void vec_ex7() {
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	//끝에서부터 출력하기
	//for (std::vector<int>::reverse_iterator i = vec.rbegin(); i != vec.rend(); ++i) {
	for (auto i = vec.rbegin(); i != vec.rend(); ++i) {
		std::cout<< typeid(i).name() << std::endl;
		std::cout << *i << std::endl;
	}

}

void vec_ex8()
{
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.emplace_back(4);
	// range-based for 문
	for (int elem : vec) {
		std::cout << "원소 : " << elem << std::endl;
	}

}

template <typename T> 
void print_vector_range_based(std::vector<T>& vec)
{
	for (const auto& elem : vec) {
		std::cout << "원소 : " << elem << std::endl;
	}
}
void vec_ex9()
{
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	// range-based for 문
	print_vector_range_based(vec);
	try {
		std::cout << "value at 0: " << vec.at(0) << std::endl;
		std::cout << "value at 5: " << vec.at(5) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}
int main()
{
	vec_ex1();
	vec_ex2();
	vec_ex3();
	vec_ex4();
	vec_ex5();
	vec_ex6(); //reverse iterator. 
	vec_ex7(); //print element in reverse. error in runtime.
	vec_ex8(); //range_based for loop
	vec_ex9();

	return 1;
}