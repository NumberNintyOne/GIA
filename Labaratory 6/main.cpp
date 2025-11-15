#include<iostream>

int main()
{
    int a = 1;
    int b = 1;
    int* pA = new int;
    pA = &a;
    int* pB = &b;
    std::cout << a << std::endl;
    *pA = *pA * 2;
    std::cout << a << std::endl;
}