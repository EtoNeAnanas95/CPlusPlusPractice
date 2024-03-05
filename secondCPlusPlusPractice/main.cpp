#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <cmath>

using namespace std;

long long factorial(int num)
{
    if (num == 1 || num == 0) return 1;
    else return num * factorial(num - 1);
}

int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    int menu;
    do
    {
        wcout << L"Выберите действие: \n";
        wcout << L"1.Сложение\n";
        wcout << L"2.Вычитание\n";
        wcout << L"3.Частное\n";
        wcout << L"4.Произвдение\n";
        wcout << L"5.Возведение в степень\n";
        wcout << L"6.Нахождения квадратного корня\n";
        wcout << L"7.Нахождение 1 процента от числа\n";
        wcout << L"8.Найти факториал числа\n";
        wcout << L"9.Выйти из программы.\n";

        wcin >> menu;

        switch (menu)
        {
            case 1:
                int firstNum;
                wcout << L"Введите первое число:\n";
                wcin >> firstNum;

                int secondNum;
                wcout << L"Введите второе число:\n";
                wcin >> secondNum;

                wcout << firstNum + secondNum << "\n";
                break;
            case 2:
                wcout << L"Введите первое число:\n";
                wcin >> firstNum;

                wcout << L"Введите второе число:\n";
                wcin >> secondNum;

                wcout << firstNum - secondNum << "\n";
                break;
            case 3:
                wcout << L"Введите первое число:\n";
                wcin >> firstNum;

                wcout << L"Введите второе число:\n";
                wcin >> secondNum;

                if (secondNum == 0)
                {
                    wcout << L"Ах ты маленький пернатый проказник, на ноль делить нельзя";
                    break;
                }

                wcout << firstNum / secondNum << "\n";
                break;
            case 4:
                wcout << L"Введите первое число:\n";
                wcin >> firstNum;

                wcout << L"Введите второе число:\n";
                wcin >> secondNum;

                wcout << firstNum * secondNum << "\n";
                break;
            case 5:
                wcout << L"Введите основание:\n";
                wcin >> firstNum;

                wcout << L"Введите степень числа:\n";
                wcin >> secondNum;

                wcout << pow(firstNum, secondNum) << "\n";
                break;
            case 6:
                wcout << L"Введите число:\n";
                wcin >> firstNum;

                wcout << sqrt(firstNum) << "\n";
                break;
            case 7:
                wcout << L"Введите число:\n";
                wcin >> firstNum;

                wcout << firstNum * 0.01 << "\n";
                break;
            case 8:
                wcout << L"Введите число:\n";
                wcin >> firstNum;

                wcout << factorial(firstNum) << "\n";
                break;
            case 9:
                wcout << L"Пока пока";
                return 0;
        }
    } while (menu != 9);
    return 0;
}