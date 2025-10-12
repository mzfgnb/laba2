#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>
#include "Models/Containers/MyVector.h"
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
    MyVector<User> users;

    bool running = true;
    while (running) {
        this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
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

            bool found = false;
            for (size_t i = 0; i < users.get_size(); ++i) {
                if (users[i].login == login) {
                    users.remove_at(i);
                    cout << "🗑️ Пользователь удалён.\n";
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "❌ Пользователь не найден.\n";
            break;
        }
        case 3: {
            cout << "\n=== Список пользователей ===\n";
            users.print_all();
            break;
        }
        case 4: {
            users.sort();
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
