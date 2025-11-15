#include <iostream>
#include <stdlib.h>
#include <limits>
#include <math.h>

#pragma region For Clause One
int f(int a)
{
    int maxDigit = 0;
    int mDCount = 1;
    while (a > 0)
    {
        int dig = a - ((a/10)*10);
        a = (a/10);
        if (dig > maxDigit)
        {
            maxDigit = dig;
            mDCount = 1;
        }
        else if (dig == maxDigit) mDCount++;
    }
    return mDCount;
}

int f(int a, int b, int c)
{
    if ((a != b) && (b != c) && (a != c))
    {
        a = abs(a);
        b = abs(b);
        c = abs(c);
        int abM = std::max(a,b);
        int bcM = std::max(b,c);
        int abm = std::min(a,b);
        int bcm = std::min(b,c);
        return (a+b+c) - std::max(abM,bcM) - std::min(abm,bcm);
    }
    else
    {
        int abm = std::min(a,b);
        int bcm = std::min(b,c);
        return std::min(abm,bcm);
    }
}

void Case1(int a)
{
    std::cout << "исп. функция счёта повторяющиейся максимальной цифры:" << std::endl;
    std::cout << f(a);
}

void Case2(int a, int b, int c)
{
    std::cout << "исп. функция средней по модулю величины трёх чисел:" << std::endl;
    std::cout << f(a,b,c);
}
#pragma endregion

void Lab1(int r)
{
    const float PI = 13.1415f;
    //Выбран тип float, так как значение константы PI вещественно.

    long double V = (4.0 * static_cast<double>(PI) * pow(static_cast<double>(r), 3))/3.0;
    //Выбран тип long double для наиболее точных вычислений вещественных значений.
    double A = 4.0 * static_cast<double>(PI) * pow(static_cast<double>(r), 2);
    //Выбран тип long double для наиболее точных вычислений вещественных значений.
    std::cout << "Объём сферы: " << V << std::endl;
    std::cout << "Площадь поверхности сферы: " << A << std::endl;

    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "Информация о использованных типах данных: " << std::endl;
    std::cout << "1) Int, занимает " << sizeof(r) * 8 << " бит(а), мин. значение = " << std::numeric_limits<int>::lowest() << ",";
    std::cout << " макс. значение = " << std::numeric_limits<int>::max() << "." << std::endl;
    std::cout << "2) Float, занимает " << sizeof(A) * 8 << " бит(а), мин. значение = " << std::numeric_limits<float>::lowest() << ",";
    std::cout << " макс. значение = " << std::numeric_limits<float>::max() << "." << std::endl;
    std::cout << "3) Long double, занимает " << sizeof(V) * 8 << " бит(а), мин. значение = " << std::numeric_limits<long double>::lowest() << ",";
    std::cout << " макс. значение = " << std::numeric_limits<long double>::max() << "." << std::endl;
}

void Clause1()
{
    std::cout << "Пункт 1" << std::endl;
    int numbers[3];
    int numId = 0;
    int zeroCount = 0;
    while (numId < 3)
    {
        std::cin >> numbers[numId];
        if (numbers[numId] == 0) zeroCount++;
        numId++;
    }

    if (zeroCount == 2)
    {
        for(int i = 0; i < 3; i++)
        {
            if(numbers[i] != 0) Case1(numbers[i]);
        }
    }
    else if(zeroCount == 0)
    {
        Case2(numbers[0], numbers[2], numbers[2]);
    }
    std::cout << std::endl;
}

void Clause2()
{
    std::cout << "Пункт 2" << std::endl;
    int r = 0;
    std::cout << "Введите целочисленное значение радиуса сферы: ";
    std::cin >> r;
    Lab1(r);
}

int main()
{
    int clauseID = -1;
    std::cout << "Введите номер выполняемого пункта:" << std::endl;
    do
    {
        std::cin >> clauseID;
    } while ((clauseID != 1) && (clauseID != 2));
    
    if(clauseID == 1) Clause1();
    else Clause2();
}