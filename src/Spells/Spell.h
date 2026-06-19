#pragma once
#include <iostream>
#include <vector>
#include "../Attributes/Type.h"
#include "../Attributes/Form.h"
#include "../Attributes/Attribute.h"

class Spell { 
protected:
    std::vector<Type> types;
    std::vector<Form> forms;
    std::vector<Attribute> attributes;

public:
    Spell(std::vector<Type> tp, std::vector<Form> fm, std::vector<Attribute> at) : types(tp), forms(fm), attributes(at) {}
    
    void printTypes() {
        for (Type& t : types) {
            std::cout << t.getType() << "\n";
        }
    }

    void printForms() {
        for (Form& f : forms) {
            std::cout << f.getForm() << "\n";
        }
    }

    void printAttributes() {
        for (Attribute& a : attributes) {
            std::cout << a.getAttribute() << "\n";
        }
    }
};