#include "Attribute.h"

Attribute::Attribute() {
    attribute = "Nein";
}

Attribute::Attribute(AttributeEnum at) {
    switch (at) {
        case AttributeEnum::Big:  attribute = "Big";  break;
        case AttributeEnum::Bulk: attribute = "Bulk"; break;
        case AttributeEnum::Heal:   attribute = "Heal";   break;
        case AttributeEnum::Peirce: attribute = "Peirce"; break;
        case AttributeEnum::Bulwark: attribute = "Bulwark"; break;
        case AttributeEnum::Explode: attribute = "Explode"; break;
        case AttributeEnum::Rejuvinate: attribute = "Rejuvinate"; break;
        case AttributeEnum::Leathal: attribute = "Leathal"; break;
        default:            attribute = "Nein";  break;
    }
}

std::string Attribute::getAttribute() {
    return attribute;
}