#include <iostream>

int main()
{
    int A[7];
    int B[3][4];

    #pragma region A
    //A Input and Fifth Division
    bool FifthDiv = true;
    for (int i = 0; i < 7; i++)
    {
        int a;
        std::cin >> a;
        if (abs(a) % 5 != 0)
        {
            FifthDiv = false;
        }
        A[i] = a;
    }

    //A Sorting
    if (FifthDiv)
    {
        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 6 - i; j++)
            {
                if(A[j] > A[j+1])
                {
                    int c = A[j];
                    A[j] = A[j+1];
                    A[j+1] = c;
                }
            }
        }
    }
    #pragma endregion

    for(int i = 0; i < 7; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    #pragma region B
    //B Input and Negative Numbers Counting
    int C[4] = {0,0,0,0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a;
            std::cin >> a;
            if(a < 0)
            {
                C[j]++;
            }
            B[i][j] = a;
        }
    }

    //Defining Column with the Maximum Count of the Negative Numbers
    int maxCount = 0;
    int maxId = 0;
    for (int i = 0; i < 4; i++)
    {
        if(C[i] > maxCount)
        {
            maxCount = C[i];
            maxId = i;
        }
    }

    //Setting this Column to '-1' value
    if(maxCount != 0)
    {
        for (int i = 0; i < 3; i++)
        {
            B[i][maxId] = -1;
        }
    }
    #pragma endregion

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cout << B[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}