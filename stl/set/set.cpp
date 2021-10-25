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

	std::cout << "������� ���ĵǼ� ���´�" << std::endl;
	print_set(s);

	std::cout << "20 �� s �� �����ΰ���? :: ";
	auto itr = s.find(20);
	if (itr != s.end()) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}

	std::cout << "25 �� s �� �����ΰ���? :: ";
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
	// ���� ��� ���ҵ��� ����ϱ�
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
	o << "[ �߿䵵: " << td.priority << "] " << td.job_desc;
	return o;
}

void set_ex3()
{
	std::set<Todo> todos;

	todos.insert(Todo(1, "�� �ϱ�"));
	todos.insert(Todo(2, "���� ���� �ϱ�"));
	todos.insert(Todo(1, "���α׷��� ������Ʈ"));
	todos.insert(Todo(3, "ģ�� ������"));
	todos.insert(Todo(2, "��ȭ ����"));
	print_set_range(todos);

	std::cout << "-------------" << std::endl;
	std::cout << "������ ���´ٸ�!" << std::endl;
	todos.erase(todos.find(Todo(2, "���� ���� �ϱ�")));
	print_set_range(todos);

}

#include <string>

template <typename T, typename C>
void print_set(std::set<T, C>& s) {
	// ���� ��� ���ҵ��� ����ϱ�
	for (const auto& elem : s) {
		std::cout << elem << " " << std::endl;
	}
}
class Todo4 {
	int priority;
	std::string job_desc;

public:
	Todo4(int priority, std::string job_desc)
		: priority(priority), job_desc(job_desc) {}

	friend struct TodoCmp;

	friend std::ostream& operator<<(std::ostream& o, const Todo4& td);
};
struct TodoCmp {
	bool operator()(const Todo4& t1, const Todo4& t2) const {
		if (t1.priority == t2.priority) {
			return t1.job_desc < t2.job_desc;
		}
		return t1.priority > t2.priority;
	}
};

std::ostream& operator<<(std::ostream& o, const Todo4& td) {
	o << "[ �߿䵵: " << td.priority << "] " << td.job_desc;
	return o;
}
void set_ex4() {
	std::set<Todo4, TodoCmp> todos;

	todos.insert(Todo4(1, "�� �ϱ�"));
	todos.insert(Todo4(2, "���� ���� �ϱ�"));
	todos.insert(Todo4(1, "���α׷��� ������Ʈ"));
	todos.insert(Todo4(3, "ģ�� ������"));
	todos.insert(Todo4(2, "��ȭ ����"));

	print_set(todos);

	std::cout << "-------------" << std::endl;
	std::cout << "������ ���´ٸ�!" << std::endl;
	todos.erase(todos.find(Todo4(2, "���� ���� �ϱ�")));
	print_set(todos);
}

int main()
{
	set_ex1();
	set_ex2();
	set_ex3();
	set_ex4();

	return 0;
}