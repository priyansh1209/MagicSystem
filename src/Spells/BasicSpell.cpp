#include "basicSpell.h"

BasicSpell::BasicSpell(Type tp, Form fm, std::vector<Attribute> at) : Spell({tp},{fm},{at}), type(tp), form(fm), attribute(at) {}