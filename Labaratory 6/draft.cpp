#include<iostream>
#include<stdlib.h>

int* F(int** M, int h, int w, size_t& size)
{
    size = 1;
    int* rowsIds = (int*)malloc(size * sizeof(int));
    rowsIds[0] = 0;
    for(int y = 1; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            if(M[y][x] == 0)
            {
                size++;
                rowsIds = (int*)realloc(rowsIds, size * sizeof(int));
                rowsIds[size - 1] = y;
                break;
            }
        }
    }
    return rowsIds;
}

void ShowMatrix(int** M, int h, int w)
{
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            std::cout << M[y][x] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
}

int main()
{
    //Clause 1
    int h = 2;
    int w = 2;
    int** A = (int**)calloc((size_t)h, sizeof(int*));
    for(int y = 0; y < h; y++)
    {
        A[y] = (int*)malloc((size_t)(w) * sizeof(int));
    }
    
    //Inputting a, b, c and d
    bool firstInput = false;
    do
    {
        if(firstInput)
        {
            std::cout << "Ошибка: отрицательные числа не принимаются!" << std::endl;
        }
        std::cout << "Введите значение A:";
        std::cin >> A[0][0];//a
        std::cout << "Введите значение B:";
        std::cin >> A[0][1];//b
        if(!firstInput)
        {
            firstInput = true;
        }
    } while ((A[0][0] < 0) || (A[0][1] < 0));
    std::cout << "Введите значение C:";
    std::cin >> A[1][0];//c
    std::cout << "Введите значение D:";
    std::cin >> A[1][1];//d

    //Resizing Matrix
    w += A[0][1];
    for(int y = 0; y < h; y++)
    {
        A[y] = (int*)realloc(A[y], (size_t)(w) * sizeof(int));
    }
    h += A[0][0];
    A = (int**)realloc(A, (size_t)(h) * sizeof(int*));
    for(int y = h - A[0][0]; y < h; y++)
    {
        A[y] = (int*)malloc((size_t)(w) * sizeof(int));
        if(y == h-1)
        {
            A[y][w-1] = A[1][1];
            A[y][w-2] = A[1][0];
        }
        if(y == h-2)
        {
            A[y][w-1] = A[0][1];
            A[y][w-2] = A[0][0];
        }
    }

    //Setting Other Cells
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            if((x >= w - 2) && (y >= h - 2)) continue;
            A[y][x] = (y*A[h-1][w-2]) + (x*A[h-1][w-1]);
        }
    }

    ShowMatrix(A, h, w);

    //Removing rows
    size_t length = 0;
    int* f = F(A,h,w,length);
    for(int i = 0; i < length; i++)
    {
        for(int j = f[i]; j < h-1; j++)
        {
            int* C;
            C = A[j];
            A[j] = A[j + 1];
            A[j + 1] = C;
        }
        for(int t = 0; t < length; t++)
        {
            f[t]--;
        }
    }
    h -= length;
    A = (int**)realloc(A, (size_t)(h) * sizeof(int*));
    ShowMatrix(A, h, w);
    free(A);

    //Clause 2
    int a1 = 0;
    int b1 = 0;
    int *pA = new int;
    int *pB = new int;
    std::cin >> a1;
    std::cin >> b1;
    pA = &a1;
    pB = &b1;
    std::cout << a1 << "_" << b1 << std::endl;
    *pA = *pA * 2;
    *pB = *pB * 2;
    std::cout << a1 << "_" << b1 << std::endl;
    pA = nullptr;
    pB = nullptr;
    delete pA;
    delete pB;
    
    return 0;
}