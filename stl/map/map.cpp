#include <iostream>
#include <map>
#include <string>


template <typename K, typename V>
void print_map(std::map<K, V>& m) {
	// 맵의 모든원소들을 출력하기
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		std::cout << itr->first << " " << itr->second << std::endl;
	}
}

void map_ex1()
{
	std::map<std::string, double> pitcher_list;

	// 참고로 투수 방어율 순위. 

	// 맵의 insert 함수는 pair 객체를 인자로 받습니다. 
	pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
	pitcher_list.insert(std::pair<std::string, double>("해커 ", 2.93));

	pitcher_list.insert(std::pair<std::string, double>("피어밴드 ", 2.95));

	// 타입을 지정하지 않아도 간단히 std::make_pair 함수로
	// std::pair 객체를 만들 수도 있습니다. 
	pitcher_list.insert(std::make_pair("차우찬", 3.04));
	pitcher_list.insert(std::make_pair("장원준", 3.05));
	pitcher_list.insert(std::make_pair("헥터 ", 3.09));

	//혹은 insert를 안쓰더라고 []로 바로 
	//원소를 추가할 수 있습니다. 
	pitcher_list["니퍼트"] = 3.56;
	pitcher_list["박종훈"] = 3.76;
	pitcher_list["켈리"] = 3.90;

	print_map(pitcher_list);

	std::cout << "박세웅 방어율은? :: " << pitcher_list["박세웅"] << std::endl;

}

template <typename K, typename V> 
void print_map_range(const std::map<K, V>& m) {
	//kv 에는 맵의 key와 value가 std::pair로 들어갑니다. 
	for (const auto& kv : m) {
		std::cout << kv.first << " " << kv.second << std::endl;
	}
}

void map_ex2()
{
	std::map<std::string, double> pitcher_list;

	pitcher_list["오승환"] = 3.58;
	print_map_range(pitcher_list);
	std::cout << "류현진 방어율은? :: " << pitcher_list["류현진"] << std::endl; // it return "0". 

	std::cout << "------------------------" << std::endl;
	print_map_range(pitcher_list);

}

template <typename K, typename V>
void search_and_print(std::map<K, V>& m, K key) {
	auto itr = m.find(key); // find(key)는 없은 m.end()를 return한다. 
	if (itr != m.end()) {
		std::cout << key << " --> " << itr->second << std::endl;
	}
	else {
		std::cout << key << "은(는) 목록에 없습니다." << std::endl;
	}
}

void map_ex3()
{
	std::cout << __FUNCTION__ << std::endl;
	std::map<std::string, double> pitcher_list;

	pitcher_list["오승환"] = 3.58;
	print_map_range(pitcher_list);
	std::cout << "------------------------" << std::endl;
	search_and_print(pitcher_list, std::string("오승환"));
	search_and_print(pitcher_list, std::string("류현진"));

	std::cout << "------------------------" << std::endl;
	print_map_range(pitcher_list);
}

void map_ex4()
{
	std::cout << std::endl << std::string(__FUNCTION__) << std::endl;

	std::map<std::string, double> pitcher_list;

	//맵의 insert 함수는 std::pair 객체를 인자로 받습니다. 
	pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
	pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.93));

	print_map_range(pitcher_list);

	// 2.23이 나올가 2.93이 나올까? 2.23.  insert시에는 같은 key가 있으면 reject됨. 
	std::cout << "박세웅 방어율은? :: " << pitcher_list["박세웅"] << std::endl;

	pitcher_list["박세웅"] = 2.93;  // 이 경우에는 overwrite된다. 
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