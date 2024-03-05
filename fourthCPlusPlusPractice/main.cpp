#include <iostream>
#include <string>
#include <Windows.h>
#include <random>
#include <algorithm>

#include <fcntl.h>



using namespace std;

wstring reverse(wstring txt)
{
    return wstring(txt.rbegin(), txt.rend());
}

wstring removeVowels(wstring txt)
{
    wstring res;
    for (wchar_t c : txt)
    {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U' &&
            c != L'а' && c != L'е' && c != L'ё' && c != L'и' && c != L'о' &&
            c != L'у' && c != L'ы' && c != L'э' && c != L'ю' && c != L'я' &&
            c != L'А' && c != L'Е' && c != L'Ё' && c != L'И' && c != L'О' &&
            c != L'У' && c != L'Ы' && c != L'Э' && c != L'Ю' && c != L'Я')
        {
            res += c;
        }

    }
    return res;
}

wstring removeConsonants(wstring txt)
{
    wstring res;
    for (wchar_t c : txt)
    {
        if (c != L'б' && c != L'в' && c != L'г' && c != L'д' && c != L'ж' && c != L'з' &&
            c != L'к' && c != L'л' && c != L'м' && c != L'н' && c != L'п' && c != L'р' &&
            c != L'с' && c != L'т' && c != L'ф' && c != L'х' && c != L'ц' && c != L'ч' &&
            c != L'ш' && c != L'щ' && c != L'ъ' && c != L'ь' && c != L'Б' && c != L'В' &&
            c != L'Г' && c != L'Д' && c != L'Ж' && c != L'З' && c != L'К' && c != L'Л' &&
            c != L'М' && c != L'Н' && c != L'П' && c != L'Р' && c != L'С' && c != L'Т' &&
            c != L'Ф' && c != L'Х' && c != L'Ц' && c != L'Ч' && c != L'Ш' && c != L'Щ' &&
            c != L'Ъ' && c != L'Ь' && c != L'й' && c != L'Й')
        {
            res += c;
        }
    }
    return res;
}

wstring shuffle(const wstring word)
{
    wstring shuffled_word = word;
    random_device rd;
    mt19937 g(rd());
    shuffle(shuffled_word.begin(), shuffled_word.end(), g);
    return shuffled_word;
}

int main() {
    //setlocale(LC_ALL, "ru_RU.UTF-8");
    _setmode(_fileno(stdout), _O_U16TEXT);

    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);

    wstring txt;

    wcout << L"Введите слово: ";
    wcin >> txt;
    wcout << endl;
    wcout << txt;
    wcout << endl;

    wcout << L"Выберите действие: " << endl;
    wcout << L"1/ Развернуть слово " << endl;
    wcout << L"2/ Убрать глассные " << endl;
    wcout << L"3/ Убрать соглассные " << endl;
    wcout << L"4/ Рандомно расикдать буквы в слове" << endl;

    int menu;

    wcin >> menu;

    switch (menu) {
        case 1:
            wcout << reverse(txt) << endl;
            break;
        case 2:
            wcout << removeVowels(txt) << endl;
            break;
        case 3:
            wcout << removeConsonants(txt) << endl;
            break;
        case 4:
            wcout << shuffle(txt) << endl;
            break;
    }

    return 0;
}