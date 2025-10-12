#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm> // для std::swap

// Универсальный шаблонный класс контейнера, аналог std::vector
template <typename T>
class MyVector {
private:
    T* data;          // динамический массив
    size_t size;      // текущее количество элементов
    size_t capacity;  // текущая вместимость

    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; ++i)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    MyVector() : data(nullptr), size(0), capacity(0) {}

    ~MyVector() {
        delete[] data;
    }

    // Добавление элемента в конец
    void push_back(const T& value) {
        if (size >= capacity)
            resize(capacity == 0 ? 2 : capacity * 2);
        data[size++] = value;
    }

    // Удаление элемента по индексу
    void remove_at(size_t index) {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        for (size_t i = index; i < size - 1; ++i)
            data[i] = data[i + 1];
        --size;
    }

    // Получение элемента по индексу
    T& operator[](size_t index) {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t get_size() const { return size; }

    // Очистка контейнера
    void clear() {
        delete[] data;
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    // Вывод всех элементов (если у типа T перегружен оператор <<)
    void print_all() const {
        for (size_t i = 0; i < size; ++i)
            std::cout << data[i] << "---------------------\n";
    }

    // Простая сортировка (пузырьком) по оператору <
    void sort() {
        for (size_t i = 0; i < size; ++i)
            for (size_t j = 0; j < size - i - 1; ++j)
                if (data[j + 1] < data[j])
                    std::swap(data[j], data[j + 1]);
    }
};
