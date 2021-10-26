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

	//s.erase(s.find("hoi")); // exception occurred. s.find("hoi") will return end(). s.erase will take past-the-end.
	//is_exist(s, std::string("hoi"));
}

// Class를 unordered_set에 사용하기 위해서는 hash_func을 만들어주고, operator == 를 만들어줘야 한다.
// 기본 타입에 대해서는 이미 존재하는 것을 사용하지만 클래스에 대해서는 만들어줘야 한다. 
#include <functional>
class Todo {
	int priority; // 중요도. 높을 수록 급한것.
	std::string job_desc;

public:
	Todo(int priority, std::string job_desc)
		: priority(priority), job_desc(job_desc) {}

	bool operator==(const Todo& t) const {
		if (priority == t.priority && job_desc == t.job_desc) return true;
		return false;
	}

	friend std::ostream& operator<<(std::ostream& o, const Todo& t);
	friend struct std::hash<Todo>;
};
// Todo hash function을 위한 함수객체(Functor)를 만들어줍니다.
// template 이라서, std:: 안에서 만들어진 template의 특정화를 수행하기때문에,
// namespace를 모 template이 있는 namespace에 맞춰줘야 한다. 
// template<> 이하가 Todo& t 에 대해서 hash_func() 이라는 특수화를 작성하는 것이다. 
namespace std {
template <>
struct hash<Todo> {
	size_t operator()(const Todo& t) const {
		hash<string> hash_func;

		return t.priority ^ (hash_func(t.job_desc));
	}
};
} // namespace std

std::ostream& operator<<(std::ostream& o, const Todo& t) {
	o << "[중요도 : " << t.priority << " ] " << t.job_desc;
	return o;
}

void unordered_set_ex3()
{
	std::unordered_set<Todo> todos;

	todos.insert(Todo(1, "농구 하기"));
	todos.insert(Todo(2, "수학 숙제 하기"));
	todos.insert(Todo(1, "프로그래밍 프로젝트"));
	todos.insert(Todo(3, "친구 만나기"));
	todos.insert(Todo(2, "영화 보기"));
	print_unordered_set(todos);
	std::cout << "----------------" << std::endl;
}

int main()
{
	unordered_set_ex1();
	unordered_set_ex2();
	unordered_set_ex3();
	return 0;
}

