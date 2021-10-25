#include <iostream>
#include <list>

void list_ex1() {
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        std::cout << *itr << std::endl;
    }
}

template <typename T> 
void print_list(std::list<T>& lst)
{
    std::cout << "[ ";
    for (const auto& elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

void list_ex2()
{
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    std::cout << "처음 리스트의 상태: " << std::endl;
    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr)
    {
        if (*itr == 20) {
            lst.insert(itr, 50);
        }
    }
    std::cout << "insert 50 before the element of 20 " << std::endl;
    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        if (*itr == 30) {
            lst.erase(itr);
            break;
        }
    }
    std::cout << "erase the element of 30 from the list" << std::endl;
    print_list(lst);

}

int main()
{
    list_ex1();
    list_ex2();

    return 0;
}

