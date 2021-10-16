#include <iostream>

#if 1
template <typename T>
void print(T arg) {
	std::cout << arg << std::endl;
}
#else
void print() {
	std::cout << std::endl;
	std::cout << "last called" << std::endl;
}
#endif

template <typename T, typename... Types>
void print(T arg, Types... args) {
	std::cout << arg << ", ";
	print(args...);
}

int print_main()
{
	print(1, 3.1, "abc");
	print(1, 2, 3, 4, 5, 6, 7);

	return 0;
}

#if 0
#include <string>

template <typename String>
std::string StrCat(const String& s) {
	return std::string(s);
}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
	return std::string(s) + StrCat(strs...);
}


#else
#include <cstring>
#include <string>

size_t GetStringSize(const char* s) {
	return strlen(s);
}
size_t GetStringSize(const std::string& s) {
	return s.size();
}

template <typename String, typename... Strings>
size_t GetStringSize(const  String& s, Strings... strs) {
	return GetStringSize(s) + GetStringSize(strs...);
}

void AppendToString(std::string* concast_str) {
	//std::cout << std::endl;
	return;
}

template <typename String, typename... Strings>
void AppendToString(std::string* concast_str, const String& s, Strings... strs) {
	concast_str->append(s);
	AppendToString(concast_str, strs...);
}

template <typename String, typename... Strings>
std::string StrCat(const String& s, Strings... strs) {
	//먼저 합쳐질 문자열의 총 길이를 구한다. 
	size_t total_size = GetStringSize(s, strs...);

	// reserve를 통해 미리 공간을 할당해 놓는다.
	std::string concat_str;
	concat_str.reserve(total_size);

	concat_str = s;
	AppendToString(&concat_str, strs...);

	return concat_str;
}

#endif
int StrCat_main()
{
	// std::string 과 const char* 을 혼합해서 사용 가능하다.
	std::cout << StrCat(std::string("this"), " ", "is", " ", std::string("a"),
		" ", std::string("sentence"));
	std::cout << std::endl;
	return 0;
}

int sum_all() { return 0; }

template <typename... Ints>
int sum_all(int num, Ints... nums)
{
	return num + sum_all(nums...);
}

template <typename... Ints>
double average(Ints... nums) {
	return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
}

int sizeof_main()
{
	// (1 + 4 + 2 + 3 + 10)/5 

	std::cout << average(1, 4, 2, 3, 10) << std::endl;

	return 0;
}

// fold 를 사용할려면, 프로젝트 -> 속성 -> 일반 -> C++ 언어표준을 17 로 변경해야 한다.
template <typename... Ints>
int varidic_sum(Ints... nums)
{
	std::cout << "called : " << sizeof...(nums) << std::endl;
	return(... + nums);
}
int fold_main()
{
	std::cout<< "5 factorial : " << varidic_sum(5,4,3,2,1) << std::endl;

	return 0;
}

template <typename Int, typename... Ints>
Int diff_from(Int start, Ints... nums) {
	return(start - ... - nums);
}

int diff_main()
{
	// 100 -1 -4 -2 -3 -10
	std::cout << diff_from(100, 1, 4, 2, 3, 10) << std::endl;

	return 0;
}

class A {
public:
	void do_something(int x) const {
		std::cout << "Do something with " << x << std::endl;
	}
};
// A "const function", denoted with the keyword const after a function declaration, 
// makes it a compiler error for this class function to change a member variable of the class. 
// However, reading of a class variables is okay inside of the function, 
// but writing inside of this function will generate a compiler error.
// 함수 내에서 읽기만 가능하고 변수에 쓰면 안된다. 컴파일 에러발생. 

template <typename T, typename... Ints>
void do_many_things(const T& t, Ints... nums) {
	// 각각의 인자들에 대해서 do_something 함수들을 호출한다. 
	(t.do_something(nums), ...);
}
int comma_main()
{
	A a;
	do_many_things(a, 1, 3, 2, 4);
	return 0;
}
int main()
{
	print_main();
	StrCat_main();
	sizeof_main();
	fold_main();
	diff_main();
	comma_main();

	return 0;
}