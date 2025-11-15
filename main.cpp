#include<iostream>
#include<stdlib.h>

int** CreateDynamicArray(int h, int w)
{
    int** arr = (int**)calloc((size_t)h, sizeof(int*));
    for(int i = 0; i < h; i++)
    {
        arr[i] = (int*)malloc((size_t)w * sizeof(int));
    }
    return arr;
}

int** AddColumnLeft(int** M, int h, int w)
{
    int** nM = CreateDynamicArray(h,w+1);
    for(int i = 0; i < h; i++)
    {
        nM[i] = (int*)realloc(M[i], (size_t)(w+1) * sizeof(int));
        int l = 0;
        int r = 0;
        for(int j = 0; j < w+1; j++)
        {
            if(j == 0)
            {
                l = nM[i][j];
            }
            else if(j == w)
            {
                nM[i][w] = l;
                nM[i][0] = 0;
            }
            else
            {
                r = nM[i][j];
                nM[i][j] = l;
                l = r;
            }
        }
    }
    return nM;
}

int** AddRowUp(int** M, int h, int w)
{
    int** nM = CreateDynamicArray(h+1,w);
    nM[0] = (int*)calloc((size_t)w, sizeof(int));
    for(int i = 1; i < h+1; i++)
    {
        nM[i] = M[i-1];
    }
    return nM;
}

int** RemoveRow(int** M, int h, int w, int rowId)
{
    int** nM = CreateDynamicArray(h-1,w);
    int lastId = 0;
    for(int i = 0; i < h; i++)
    {
        if(i != rowId)
        {
            nM[lastId] = M[i];
            lastId++;
        }
    }
    return nM;
}

int zeroRowsCount(int** arr, int h, int w)
{
    int count = 0;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(arr[i][j] == 0)
            {
                count++;
                break;
            }
        }
    }
    return count;
}

int* f(int** arr, int h, int w)
{
    int* t = new int[h];
    t[0] = 0;
    for(int i = 1; i < h; i++) t[i] = -1;

    for(int i = 1; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(arr[i][j] == 0)
            {
                t[i] = i;
                break;
            }
        }
    }
    return t;
}

void ShowMatrix(int** M, int h, int w)
{
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            std::cout << M[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    //Creating dynamic array
    int w = 2;
    int h = 2;
    int** A = CreateDynamicArray(h,w);

    //Inputting a, b, c and d
    do
    {
        std::cin >> A[0][0];//a
        std::cin >> A[0][1];//b
    } while ((A[0][0] < 0) || (A[0][1] < 0));
    std::cin >> A[1][0];//c
    std::cin >> A[1][1];//d

    ShowMatrix(A, h, w);
    int a = A[0][0];
    int b = A[0][1];
    int c = A[1][0];
    int d = A[1][1];
    for(int i = 0; i < a; i++)
    {
        A = AddRowUp(A, h, w);
        h++;
    }
    for(int i = 0; i < b; i++)
    {
        A = AddColumnLeft(A, h, w);
        w++;
    }
    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            A[y][x] = (x*d) + (y*c);
        }
    }
    A[h-2][w-2] = a;
    A[h-2][w-1] = b;
    A[h-1][w-2] = c;
    A[h-1][w-1] = d;
    ShowMatrix(A, h, w);
    while(zeroRowsCount(A,h,w) > 0)
    {
        int* rows = f(A,h,w);
        for(int i = 0; i < h; i++)
        {
            if(rows[i] != -1)
            {
                A = RemoveRow(A, h, w, rows[i]);
                h--;
                break;
            }
        }
    }
    ShowMatrix(A, h, w);
    free(A);

    //----------------------------------------------------------------------------------------------------------------------------------------------

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