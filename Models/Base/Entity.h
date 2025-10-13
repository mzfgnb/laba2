#pragma once
#include <iostream>

class Entity {
public:
    virtual void print() const = 0;     
    virtual bool less(const Entity& other) const = 0; 
    virtual ~Entity() = default;
};
