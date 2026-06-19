#pragma once
#include <string>
#include "../Enums/TypeEnum.h"

class Type {
private:
    std::string type;

public:
    Type();
    Type(TypeEnum tp);
    std::string getType();
};