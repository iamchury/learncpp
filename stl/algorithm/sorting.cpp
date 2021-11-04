#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}
void sort_ex() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(2);

    std::cout << "정렬 전 ----" << std::endl;
    print(vec.begin(), vec.end());
    std::sort(vec.begin(), vec.end());

    std::cout << "정렬 후 ----" << std::endl;
    print(vec.begin(), vec.end());
}

struct int_compare {
    bool operator()(const int& a, const int& b) const { return a > b; }
};
void sort_op_ex() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(2);

    std::cout << "정렬 전 ----" << std::endl;
    print(vec.begin(), vec.end());
    std::sort(vec.begin(), vec.end(),int_compare());

    std::cout << "Reverse 정렬 후 ----" << std::endl;
    print(vec.begin(), vec.end());
}

void sort_greater_ex() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(2);

    std::cout << "정렬 전 ----" << std::endl;
    print(vec.begin(), vec.end());
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    std::cout << "Greater Reverse 정렬 후 ----" << std::endl;
    print(vec.begin(), vec.end());
}
void partial_sort_ex() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(2);

    std::cout << "정렬 전 ----" << std::endl;
    print(vec.begin(), vec.end());
    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());

    std::cout << "Partial sorting 정렬 후 ----" << std::endl;
    print(vec.begin(), vec.end());
}

template <typename Iter>
void sprint(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}
struct User {
    std::string name;
    int age;

    User(std::string name, int age) : name(name), age(age) {}

    bool operator<(const User& u) const { return age < u.age; }
};

std::ostream& operator<<(std::ostream& o, const User& u) {
    o << u.name << " , " << u.age;
    return o;
}

void stable_sort_ex() {
    std::vector<User> vec;
    for (int i = 0; i < 100; i++) {
        std::string name = "";
        name.push_back('a' + i / 26);
        name.push_back('a' + i % 26);
        vec.push_back(User(name, static_cast<int>(rand() % 10)));
    }

    std::vector<User> vec2 = vec;

    std::cout << "정렬 전 ----" << std::endl;
    sprint(vec.begin(), vec.end());

    std::sort(vec.begin(), vec.end());

    std::cout << "정렬 후 ----" << std::endl;
    sprint(vec.begin(), vec.end());

    std::cout << "stable_sort 의 경우 ---" << std::endl;
    std::stable_sort(vec2.begin(), vec2.end());
    sprint(vec2.begin(), vec2.end());
}
int main()
{
    sort_ex();
    sort_op_ex();
    sort_greater_ex();
    partial_sort_ex();
    stable_sort_ex();
}


