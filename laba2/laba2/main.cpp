#include <iostream>
#include <vector>
#include <algorithm>
#include "Models/User/User.h"
#include "Models/Mails/Mail.h"
using namespace std;

void PrintMenu() {
    cout << "\n=== Главное меню ===\n";
    cout << "1. Добавить пользователя\n";
    cout << "2. Удалить пользователя\n";
    cout << "3. Показать всех пользователей\n";
    cout << "4. Отсортировать пользователей по логину\n";
    cout << "0. Выход\n";
    cout << "Выберите пункт: ";
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    vector<User> users;

    bool running = true;
    while (running) {
        PrintMenu();
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            User u;
            cin >> u; // ввод через перегруженный >>
            users.push_back(u);
            cout << "✅ Пользователь добавлен.\n";
            break;
        }
        case 2: {
            string login;
            cout << "Введите логин для удаления: ";
            cin >> login;

            auto it = remove_if(users.begin(), users.end(), [&](const User& u) {
                return u.login == login;
                });
            if (it != users.end()) {
                users.erase(it, users.end());
                cout << "🗑️ Пользователь удалён.\n";
            }
            else {
                cout << "❌ Пользователь не найден.\n";
            }
            break;
        }
        case 3: {
            cout << "\n=== Список пользователей ===\n";
            for (const auto& u : users)
                cout << u << "---------------------\n"; // вывод через <<
            break;
        }
        case 4: {
            sort(users.begin(), users.end());
            cout << "📋 Список отсортирован по логину.\n";
            break;
        }
        case 0:
            running = false;
            cout << "👋 Выход...\n";
            break;
        default:
            cout << "❌ Неверный пункт меню.\n";
        }
    }

    return 0;
}
