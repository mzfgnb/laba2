#include "User.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const USER& u) {
    os << "Имя: " << u.name << "\n"
        << "Фамилия: " << u.surname << "\n"
        << "Возраст: " << u.age << "\n"
        << "Логин: " << u.login << "\n";
    return os;
}

istream& operator>>(istream& is, USER& u) {
    cout << "Введите имя: ";
    is >> u.name;
    cout << "Введите фамилию: ";
    is >> u.surname;
    cout << "Введите возраст: ";
    is >> u.age;
    cout << "Введите логин: ";
    is >> u.login;
    cout << "Введите пароль: ";
    is >> u.password;
    return is;
}