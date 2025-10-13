#pragma once
#include <iostream>
#include <string>
#include "../Containers/MyVector.h"
#include "../Mails/Mail.h"
#include "../Base/Entity.h"
using namespace std;

class USER : public Entity {
public:
    std::string name;
    std::string surname;
    unsigned int age;
    std::string login;
    std::string password;

    bool operator==(const USER& other) const { return login == other.login; }
    bool operator<(const USER& other) const { return login < other.login; }

    void print() const override {
        std::cout << "Имя: " << name << "\n"
            << "Фамилия: " << surname << "\n"
            << "Возраст: " << age << "\n"
            << "Логин: " << login << "\n";
    }

    bool less(const Entity& other) const override {
        const USER& u = dynamic_cast<const USER&>(other);
        return login < u.login;
    }

    friend std::ostream& operator<<(std::ostream& os, const USER& u);
    friend std::istream& operator>>(std::istream& is, USER& u);
};

class User : public USER {
public: 
    User() {
    }
    MyVector<Mail> mails;

};

class Admin : public USER {
public:
    Admin() {
    }
};
