#pragma once
#include <iostream>
#include <string>
#include "../Mails/Mail.h"
using namespace std;

class USER {
public:
    std::string name;
    std::string surname;
    unsigned int age;
    std::string login;
    std::string password;

    bool operator==(const USER& other) const { return login == other.login; }
    bool operator<(const USER& other) const { return login < other.login; }

    friend std::ostream& operator<<(std::ostream& os, const USER& u);
    friend std::istream& operator>>(std::istream& is, USER& u);
};

class User : public USER {
public: 
    User() {
        cout << "Enter user login:";
        cin >> this->login;

        cout << endl << "Enter user password: ";
        cin >> this->password;
        cout << endl;
    }
    Mail mails[10];

};

class Admin : public USER {
public:
    Admin() {
        cout << "Enter Admin login: ";
        cin >> this->login;

        cout << endl << "Enter Admin password: ";
        cin >> this->password;
        cout << endl;
    }
};
