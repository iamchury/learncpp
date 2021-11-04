#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> vec;
    std::vector<int>::iterator itr;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "ó�� vec ���� ------" << std::endl;
    std::cout << "Vector size : " << vec.size() << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "���Ϳ��� ���� 3 �� ���� ���� ---" << std::endl;
    //vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());
    itr= std::remove(vec.begin(), vec.end(), 3);
    std::cout << "Vector size : " << vec.size() << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "���Ϳ��� ���� 3 �� ���� erased ---" << std::endl;
    vec.erase(itr, vec.end());
    std::cout << "Vector size : " << vec.size() << std::endl;
    print(vec.begin(), vec.end());
}


