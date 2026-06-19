#pragma once
#include <string>
#include "../Enums/AttributeEnum.h"

class Attribute {
private:
    std::string attribute;

public:
    Attribute();
    Attribute(AttributeEnum at);
    std::string getAttribute();
};