#pragma once
#include <string>
#include "../Enums/FormEnum.h"

class Form {
private:
    std::string form;

public:
    Form();
    Form(FormEnum fm);
    std::string getForm();
};