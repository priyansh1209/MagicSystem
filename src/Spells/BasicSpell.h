#pragma once
#include "Spell.h"
#include "../Attributes/Type.h"

class BasicSpell : public Spell {
protected:
    Type type;

public:
    BasicSpell(Type tp);
};