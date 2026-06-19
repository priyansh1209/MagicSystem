#pragma once
#include <vector>
#include "Spell.h"
#include "../Attributes/Type.h"
#include "../Attributes/Form.h"
#include "../Attributes/Attribute.h"

class BasicSpell : public Spell {
protected:
    Type type;
    Form form;
    std::vector<Attribute> attribute;

public:
    BasicSpell(Type tp, Form fm, std::vector<Attribute> at);
};