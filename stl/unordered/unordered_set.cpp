#include <iostream>
#include <string>
#include <unordered_set>

template <typename K>
void print_unordered_set(const std::unordered_set<K>& m) {
	// set의 모든 원소들을 출력하기
	for (const auto& elem : m) {
		std::cout << elem << std::endl;
	}
}

void unordered_set_ex1() {
	std::unordered_set<std::string> s;

	s.insert("hi");
	s.insert("my");
	s.insert("name");
	s.insert("is");
	s.insert("psi");
	s.insert("welcome");
	s.insert("to");
	s.insert("c++");

	print_unordered_set(s);
}

template <typename K>
void is_exist(std::unordered_set<K>& s, K key) {
	auto itr = s.find(key);
	if (itr != s.end()) {
		std::cout << key << " 가 존재!" << std::endl;
	}
	else {
		std::cout << key << " 가 없다" << std::endl;
	}
}

void unordered_set_ex2()
{
	std::unordered_set<std::string> s;

	s.insert("hi");
	s.insert("my");
	s.insert("name");
	s.insert("is");
	s.insert("psi");
	s.insert("welcome");
	s.insert("to");
	s.insert("c++");

	print_unordered_set(s);
	std::cout << "----------------" << std::endl;
	is_exist(s, std::string("c++"));
	is_exist(s, std::string("c"));

	std::cout << "----------------" << std::endl;
	std::cout << "'hi' 를 삭제" << std::endl;
	// s.find()는 iterator를 return한다. s.erase(iter)를 입력 argument로 한다. 
	s.erase(s.find("hi"));
	is_exist(s, std::string("hi"));

	s.erase(s.find("hoi")); // exception occurred. s.find("hoi") will return end(). s.erase will take past-the-end.
	is_exist(s, std::string("hoi"));
}

int main()
{
	unordered_set_ex1();
	unordered_set_ex2();

	return 0;
}

