#include <iostream>
#include <math.h>

int main() {
    short A = 0;
    unsigned short i = 1;
    std::cout << "Введите значение переменной A:";
    std::cin >> A;
    std::cin >> i;
    std::cout << "1)------------------------------------------------------------------" << std::endl;
    short bit = int((A >> (i - 1)) & 1);
    if (bit != 0)
    {
        unsigned int A;
        unsigned int B;
        unsigned int C;
        std::cin >> A;
        std::cin >> B;
        std::cin >> C;

        if ((A < B) && (B < C)) std::cout << static_cast<int>(C-B-A) << std::endl;
        else if (A % C == 0) std::cout << static_cast<int>(A/C+B) << std::endl;
        else std::cout << static_cast<int>(A+B+C) << std::endl;
    }
    else std::cout << static_cast<int>(A|A) << std::endl;
    std::cout << "2)------------------------------------------------------------------" << std::endl;
    int N = 1;
    NInput:
    std::cin >> N;
    switch(N)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            std::cout << "31" << std::endl;
            break;
        
        //February
        case 2:
            std::cout << "28" << std::endl;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            std::cout << "30" << std::endl;
            break;

        //Error
        default:
            std::cout << "Ошибочный ввод номера месяца! Введите номер месяца снова:";
            goto NInput;
            break;
    }

    return 0;
}