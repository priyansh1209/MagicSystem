#include <iostream>
#include "TypeEnum.cpp"

class Type{
    private:
        std::string type;

    public:
        Type(TypeEnum tp){
            switch (tp) {
                case TypeEnum::Fire: type = "Fire";
                case TypeEnum::Water: type = "Water";
                case TypeEnum::Air:  type = "Air";
                case TypeEnum::Earth:  type = "Earth";
                default: type = "Nein";
            }
        }
};