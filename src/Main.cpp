#include <iostream>
#include "Enums/TypeEnum.h"
#include "Attributes/Type.h"
#include "Spells/Spell.h"  
#include "Spells/BasicSpell.h"

int main(){
    Type Fire(TypeEnum::Fire);
    Type Water(TypeEnum::Water);
    Type Air(TypeEnum::Air);
    Type Earth(TypeEnum::Earth);
    BasicSpell spell(Fire);
    spell.printTypes();
}