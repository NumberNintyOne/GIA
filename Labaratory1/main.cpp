#include <iostream>
#include <math.h>

int main()
{
    unsigned int r = 0;
    //Выбран тип unsigned int, так как радиус окружности всегда больше нуля, и он целочисленнен по условию.
    const float PI = 3.1415f;
    //Выбран тип float, так как значение константы PI вещественно.

    std::cout << "Введите целочисленное значение радиуса сферы: ";
    std::cin >> r;
    const long double V = (4.0 * static_cast<double>(PI) * pow(static_cast<double>(r), 3))/3.0;
    //Выбран тип long double для наиболее точных вычислений вещественных значений.
    const long double A = 4.0 * static_cast<double>(PI) * pow(static_cast<double>(r), 2);
    //Выбран тип long double для наиболее точных вычислений вещественных значений.
    std::cout << "Объём сферы: " << V << std::endl;
    std::cout << "Площадь поверхности сферы: " << A << std::endl;

    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "Информация о использованных типах данных: " << std::endl;
    std::cout << "1) Unsigned int, занимает " << sizeof(r) * 8 << " бит(а), мин. значение = 0,";
    std::cout << " макс. значение = " << static_cast<long long>(pow(2,32)) - 1 << "." << std::endl;
    std::cout << "2) Float, занимает " << sizeof(PI) * 8 << " бит(а), мин. значение = " << static_cast<long double>(-3.40282f * pow(10, 38)) << ",";
    std::cout << " макс. значение = " << static_cast<long double>(3.40282f * pow(10, 38)) - 1 << "." << std::endl;
    std::cout << "3) Long double, занимает " << sizeof(V) * 8 << " бит(а), мин. значение = " << static_cast<long double>(-1.18973f * pow(10, 4932)) << ",";
    std::cout << " макс. значение = " << static_cast<long double>(1.18973f * pow(10, 4932)) -1 << "." << std::endl;
    
    return 0;
}