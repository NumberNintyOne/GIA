#include<iostream>
#include<stdlib.h>
#include<array>



int main()
{
    //Creating dynamic array
    const int w = 2;
    const int h = 2;
    std::array<std::array<int, w>, h> A = (std::array<std::array<int, w>, h>)calloc((size_t)(h), sizeof(std::array<int, w>));
    return 0;
}