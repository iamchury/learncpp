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

    std::cout << "���� �� ----" << std::endl;
    print(vec.begin(), vec.end());
    std::sort(vec.begin(), vec.end());

    std::cout << "���� �� ----" << std::endl;
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

    std::cout << "���� �� ----" << std::endl;
    print(vec.begin(), vec.end());
    std::sort(vec.begin(), vec.end(),int_compare());

    std::cout << "Reverse ���� �� ----" << std::endl;
    print(vec.begin(), vec.end());
}

int main()
{
    sort_ex();
    sort_op_ex();
}
