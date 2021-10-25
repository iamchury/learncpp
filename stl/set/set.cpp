#include <iostream>
#include <set>

template <typename T>
void print_set(std::set<T>& s) {
	std::cout << "[ ";
	for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
		std::cout << *itr << " ";
	}
	std::cout << " ] " << std::endl;

}

void set_ex1()
{
	std::set<int> s;
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(40);
	s.insert(30);

	std::cout << "순서대로 정렬되서 나온다" << std::endl;
	print_set(s);

	std::cout << "20 이 s 의 원소인가요? :: ";
	auto itr = s.find(20);
	if (itr != s.end()) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}

	std::cout << "25 가 s 의 원소인가요? :: ";
	itr = s.find(25);
	if (itr != s.end()) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}
}

void set_ex2()
{
	std::set<int> s;
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(20);
	s.insert(10);

	print_set(s);
}

template <typename T>
void print_set_range(std::set<T>& s) {
	// 셋의 모든 원소들을 출력하기
	for (const auto& elem : s) {
		std::cout << elem << " " << std::endl;
	}
}
class Todo {
	int priority;
	std::string job_desc;

public:
	Todo(int priority, std::string job_desc) :
		priority(priority), job_desc(job_desc) {}

	bool operator<(const Todo& t) const{
		if (priority == t.priority) {
			return job_desc < t.job_desc;
		}
		return priority < t.priority;
	}
	friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};
std::ostream& operator<<(std::ostream& o, const Todo& td) {
	o << "[ 중요도: " << td.priority << "] " << td.job_desc;
	return o;
}

void set_ex3()
{
	std::set<Todo> todos;

	todos.insert(Todo(1, "농구 하기"));
	todos.insert(Todo(2, "수학 숙제 하기"));
	todos.insert(Todo(1, "프로그램이 프로젝트"));
	todos.insert(Todo(3, "친구 만나기"));
	todos.insert(Todo(2, "영화 보기"));
	print_set_range(todos);

	std::cout << "-------------" << std::endl;
	std::cout << "숙제를 끝냈다면!" << std::endl;
	todos.erase(todos.find(Todo(2, "수학 숙제 하기")));
	print_set_range(todos);

}
int main()
{
	set_ex1();
	set_ex2();
	set_ex3();

	return 0;
}