#pragma once
#include <iostream>
#include <vector>
#include "../Attributes/Type.h"

class Spell { 
protected:
    std::vector<Type> types;

public:
    Spell(std::vector<Type> tp) : types(tp) {}
    
    void printTypes() {
        for (Type& t : types) {
            std::cout << t.getType() << "\n";
        }
    }
};