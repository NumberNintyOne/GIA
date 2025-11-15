#include <iostream>
#include <math.h>
#include <limits>
#include <string>

int main()
{
    int n = 0;
    std::cin >> n;

    int sumNeg = 0;
    int maxNum = std::numeric_limits<int>::lowest();
    int maxNumCount = 0;

    for (int i = 0; i < n; i++)
    {
        int a = 0;
        std::cin >> a;

        if (a >= 0) continue;

        sumNeg += a;
        if (a > maxNum)
        {
            maxNum = a;
            maxNumCount = 1;
        }
        else if (a == maxNum)
        {
            maxNumCount++;
        }
    }

    if(maxNumCount != 0)
    {
        std::cout << sumNeg << std::endl;
        std::cout << maxNum << std::endl;
        std::cout << maxNumCount << std::endl;
    }
    else std::cout << "Нет неотрицательных чисел!" << std::endl;

    int x = 0;
    std::cin >> x;
    x = abs(x);
    while(x >= 1000)
    {
        std::cin >> x;
    }

    int maxNumeral = 0;
    while (x > 0)
    {
        int numeral = x - (static_cast<int>(x/10)*10);
        if(numeral > maxNumeral) maxNumeral = numeral;
        x = static_cast<int>(x/10);
    }

    std::cout << maxNumeral;
    return 0;
}