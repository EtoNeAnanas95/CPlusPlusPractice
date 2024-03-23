#include <iostream>
#include <Windows.h>
#include <fcntl.h>

using namespace std;

class BankAccount {
    friend bool transfer(BankAccount& accountNumberFrom, BankAccount& accountNumberTo, double amount);
private:
    short _accountNumber; //номер банковского счёта
    double _balance; //баланс
    double _interestRate; //процентная ставка

public:
    BankAccount(int accountNumber, double& balance) {
        this->_accountNumber = accountNumber;
        this->_balance = balance;
    }

    void deposit(double value) { //положить средства
        if (value > 0) this->_balance += value;
    }

    void withdraw(double amount) { //вывод средств
        if (amount > 0) this->_balance -= amount;
    }

    double getBalance() { //получение баланса
        return _balance;
    }

    double getInterest() { //сумма процентов заработка
        return _balance * _interestRate * (1.0 / 12.0) ? _interestRate > 0: 0;
    }

    void setInterestRate(double interestRate) { //обновить процентную ставку
        this->_interestRate = interestRate;
    }

    int getAccountNumber() { //получить номер банковского счёта
        return _accountNumber;
    }
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (amount <= from.getBalance() && amount > 0) {
        from._balance -= amount;
        to._balance += amount;
        return true;
    }
    else return false;
}

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251); //эти три строки это локализация

    double accountNumber;
    wcout << L"Введите баланс первого аккаунта: " << endl;
    wcin >> accountNumber;
    BankAccount firstAccount = BankAccount(1, accountNumber);
    wcout << L"Введите баланс второго аккаунта: " << endl;
    wcin >> accountNumber;
    BankAccount secondAccount = BankAccount(2, accountNumber);

    firstAccount.deposit(100);
    secondAccount.deposit(100);
    wcout << L"Баланс 1 пользователя: " << firstAccount.getBalance() << endl;
    wcout << L"Баланс 2 пользователя: " << secondAccount.getBalance() << endl;
    firstAccount.setInterestRate(-1);
    secondAccount.setInterestRate(0.15);
    wcout << L"Проценты 1 пользователя: " << firstAccount.getInterest() << endl;
    wcout << L"Проценты 2 пользователя: " << secondAccount.getInterest() << endl;
    firstAccount.withdraw(10);
    secondAccount.withdraw(10);
    wcout << L"Баланс 1 пользователя: " << firstAccount.getBalance() << endl;
    wcout << L"Баланс 2 пользователя: " << secondAccount.getBalance() << endl;
    wcout << L"Статус перевода с 1 на 2: " << transfer(firstAccount, secondAccount, 100) << endl;
    wcout << L"Статус перевода с 1 на 2: " << transfer(firstAccount, secondAccount, 100) << endl;

    return 0;
}