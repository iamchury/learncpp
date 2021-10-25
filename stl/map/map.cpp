#include <iostream>
#include <map>
#include <string>


template <typename K, typename V>
void print_map(std::map<K, V>& m) {
	// ���� �����ҵ��� ����ϱ�
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		std::cout << itr->first << " " << itr->second << std::endl;
	}
}

void map_ex1()
{
	std::map<std::string, double> pitcher_list;

	// ����� ���� ����� ����. 

	// ���� insert �Լ��� pair ��ü�� ���ڷ� �޽��ϴ�. 
	pitcher_list.insert(std::pair<std::string, double>("�ڼ���", 2.23));
	pitcher_list.insert(std::pair<std::string, double>("��Ŀ ", 2.93));

	pitcher_list.insert(std::pair<std::string, double>("�Ǿ��� ", 2.95));

	// Ÿ���� �������� �ʾƵ� ������ std::make_pair �Լ���
	// std::pair ��ü�� ���� ���� �ֽ��ϴ�. 
	pitcher_list.insert(std::make_pair("������", 3.04));
	pitcher_list.insert(std::make_pair("�����", 3.05));
	pitcher_list.insert(std::make_pair("���� ", 3.09));

	//Ȥ�� insert�� �Ⱦ������ []�� �ٷ� 
	//���Ҹ� �߰��� �� �ֽ��ϴ�. 
	pitcher_list["����Ʈ"] = 3.56;
	pitcher_list["������"] = 3.76;
	pitcher_list["�̸�"] = 3.90;

	print_map(pitcher_list);

	std::cout << "�ڼ��� �������? :: " << pitcher_list["�ڼ���"] << std::endl;

}

template <typename K, typename V> 
void print_map_range(const std::map<K, V>& m) {
	//kv ���� ���� key�� value�� std::pair�� ���ϴ�. 
	for (const auto& kv : m) {
		std::cout << kv.first << " " << kv.second << std::endl;
	}
}

void map_ex2()
{
	std::map<std::string, double> pitcher_list;

	pitcher_list["����ȯ"] = 3.58;
	print_map_range(pitcher_list);
	std::cout << "������ �������? :: " << pitcher_list["������"] << std::endl; // it return "0". 

	std::cout << "------------------------" << std::endl;
	print_map_range(pitcher_list);

}

template <typename K, typename V>
void search_and_print(std::map<K, V>& m, K key) {
	auto itr = m.find(key); // find(key)�� ���� m.end()�� return�Ѵ�. 
	if (itr != m.end()) {
		std::cout << key << " --> " << itr->second << std::endl;
	}
	else {
		std::cout << key << "��(��) ��Ͽ� �����ϴ�." << std::endl;
	}
}

void map_ex3()
{
	std::cout << __FUNCTION__ << std::endl;
	std::map<std::string, double> pitcher_list;

	pitcher_list["����ȯ"] = 3.58;
	print_map_range(pitcher_list);
	std::cout << "------------------------" << std::endl;
	search_and_print(pitcher_list, std::string("����ȯ"));
	search_and_print(pitcher_list, std::string("������"));

	std::cout << "------------------------" << std::endl;
	print_map_range(pitcher_list);
}

void map_ex4()
{
	std::cout << std::endl << std::string(__FUNCTION__) << std::endl;

	std::map<std::string, double> pitcher_list;

	//���� insert �Լ��� std::pair ��ü�� ���ڷ� �޽��ϴ�. 
	pitcher_list.insert(std::pair<std::string, double>("�ڼ���", 2.23));
	pitcher_list.insert(std::pair<std::string, double>("�ڼ���", 2.93));

	print_map_range(pitcher_list);

	// 2.23�� ���ð� 2.93�� ���ñ�? 2.23.  insert�ÿ��� ���� key�� ������ reject��. 
	std::cout << "�ڼ��� �������? :: " << pitcher_list["�ڼ���"] << std::endl;

	pitcher_list["�ڼ���"] = 2.93;  // �� ��쿡�� overwrite�ȴ�. 
	print_map_range(pitcher_list);
}

int main()
{
	map_ex1();
	map_ex2();
	map_ex3();
	map_ex4();

	return 0;
}