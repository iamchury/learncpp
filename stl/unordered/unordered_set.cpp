#include <iostream>
#include <string>
#include <unordered_set>

template <typename K>
void print_unordered_set(const std::unordered_set<K>& m) {
	// set�� ��� ���ҵ��� ����ϱ�
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
		std::cout << key << " �� ����!" << std::endl;
	}
	else {
		std::cout << key << " �� ����" << std::endl;
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
	std::cout << "'hi' �� ����" << std::endl;
	// s.find()�� iterator�� return�Ѵ�. s.erase(iter)�� �Է� argument�� �Ѵ�. 
	s.erase(s.find("hi"));
	is_exist(s, std::string("hi"));

	//s.erase(s.find("hoi")); // exception occurred. s.find("hoi") will return end(). s.erase will take past-the-end.
	//is_exist(s, std::string("hoi"));
}

// Class�� unordered_set�� ����ϱ� ���ؼ��� hash_func�� ������ְ�, operator == �� �������� �Ѵ�.
// �⺻ Ÿ�Կ� ���ؼ��� �̹� �����ϴ� ���� ��������� Ŭ������ ���ؼ��� �������� �Ѵ�. 
#include <functional>
class Todo {
	int priority; // �߿䵵. ���� ���� ���Ѱ�.
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
// Todo hash function�� ���� �Լ���ü(Functor)�� ������ݴϴ�.
// template �̶�, std:: �ȿ��� ������� template�� Ư��ȭ�� �����ϱ⶧����,
// namespace�� �� template�� �ִ� namespace�� ������� �Ѵ�. 
// template<> ���ϰ� Todo& t �� ���ؼ� hash_func() �̶�� Ư��ȭ�� �ۼ��ϴ� ���̴�. 
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
	o << "[�߿䵵 : " << t.priority << " ] " << t.job_desc;
	return o;
}

void unordered_set_ex3()
{
	std::unordered_set<Todo> todos;

	todos.insert(Todo(1, "�� �ϱ�"));
	todos.insert(Todo(2, "���� ���� �ϱ�"));
	todos.insert(Todo(1, "���α׷��� ������Ʈ"));
	todos.insert(Todo(3, "ģ�� ������"));
	todos.insert(Todo(2, "��ȭ ����"));
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

