#include "Type.h"

Type::Type() {
    type = "Nein";
}

Type::Type(TypeEnum tp) {
    switch (tp) {
        case TypeEnum::Fire:  type = "Fire";  break;
        case TypeEnum::Water: type = "Water"; break;
        case TypeEnum::Air:   type = "Air";   break;
        case TypeEnum::Earth: type = "Earth"; break;
        default:              type = "Nein";  break;
    }
}

std::string Type::getType() {
    return type;
}