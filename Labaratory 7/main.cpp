#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<limits>
#include<math.h>
#include<array>

#pragma region 1-6 voids
//1
void ViewArray(std::vector<int>& arr)
{
    if (arr.size() == 0)
    {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    for(int i = 0; i < arr.size()-1; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << arr[arr.size()-1];
    std::cout << "]" << std::endl;
}

//2
void AddToBeginning(std::vector<int>& arr)
{
    int a;
    std::cin >> a;
    arr.insert(arr.begin(), a);
}

//3
void AddToEnd(std::vector<int>& arr)
{
    int a;
    std::cin >> a;
    arr.push_back(a);
}

//4
void ClearArray(std::vector<int>& arr)
{
    arr.erase(arr.begin(), arr.end());
}

//5
void FindElementWithIndex(std::vector<int>& arr)
{
    int a;
    std::cin >> a;

    if (arr.size() == 0)
    {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    for(int i = 0; i < arr.size()-1; i++)
    {
        if(arr[i] == a) std::cout << i << " ";
    }
    if(arr[arr.size()-1] == a) std::cout << arr.size()-1;
    std::cout << "]" << std::endl;
}

//6
void F(std::vector<int>& arr)
{
    ViewArray(arr);
    int m = std::numeric_limits<int>::max();
    for(int i = 0; i < arr.size(); i++)
    {
        if((abs(arr[i]) < m) && (arr[i] != 0)) m = abs(arr[i]);
    }
    for(int i = 0; i < m; i++) arr.push_back(0);
    ViewArray(arr);
}
#pragma endregion

void CallF(int callId, std::vector<int>& arr)
{
    switch(callId)
    {
        case 1:
        ViewArray(arr);
        break;

        case 2:
        AddToBeginning(arr);
        break;

        case 3:
        AddToEnd(arr);
        break;

        case 4:
        ClearArray(arr);
        break;

        case 5:
        FindElementWithIndex(arr);
        break;

        case 6:
        F(arr);
        break;
    }
}

int ProgramIteration(std::vector<int>& arr)
{
    int callId = -1;
    std::cin >> callId;
    if(callId != 0) CallF(callId, arr);
    return callId;
}

void ShowMatrix(std::array<std::array<int, 5>, 2>& M)
{
    for(int y = 0; y < 2; y++)
    {
        for(int x = 0; x < 5; x++)
        {
            std::cout << M[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

void SortMatrixA(std::array<std::array<int, 5>, 2> M)
{
    std::sort(M[0].begin(), M[0].end());
    std::sort(M[1].begin(), M[1].end());
}

void SortMatrixB(std::array<std::array<int, 5>, 2>& M)
{
    std::sort(M[0].begin(), M[0].end());
    std::sort(M[1].begin(), M[1].end());
}

void SortMatrixC(std::array<std::array<int*, 5>, 2> p)
{
    std::sort(p[0].begin(), p[0].end(), [](int* a, int* b){ return *a < *b; });
    std::sort(p[1].begin(), p[1].end(), [](int* a, int* b){ return *a < *b; });
}

int main()
{
    //Clause 1
    std::vector<int> vec;
    vec.reserve(100'000);
    int iteration = -1;
    do
    {
        iteration = ProgramIteration(vec);
    } while (iteration != 0);
    //Clause 2
    std::array<std::array<int, 5>, 2> mtx = {{{((rand() % 21) - 10),((rand() % 21) - 10),((rand() % 21) - 10),((rand() % 21) - 10),((rand() % 21) - 10)},
     {((rand() % 21) - 10),((rand() % 21) - 10),((rand() % 21) - 10),((rand() % 21) - 10),((rand() % 21) - 10)}}};
    std::array<std::array<int*, 5>, 2> ptx;
    for(int y = 0; y < 2; y++)
    {
        for(int x = 0; x < 5; x++)
        {
            ptx[y][x] = &mtx[y][x];
        }
    }
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Изначальная матрица:" << std::endl;
    ShowMatrix(mtx);
    std::cout << "--------------------------------------" << std::endl;
    SortMatrixA(mtx);
    ShowMatrix(mtx);
    std::cout << "Вывод: Передача массива по значению не меняет оригинальную переменную." << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    SortMatrixC(ptx);
    ShowMatrix(mtx);
    std::cout << "Вывод: Передача массива по указателю не меняет оригинальную переменную." << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    SortMatrixB(mtx);
    ShowMatrix(mtx);
    std::cout << "Вывод: Передача массива по ссылке меняет оригинальную переменную." << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    return 0;
}