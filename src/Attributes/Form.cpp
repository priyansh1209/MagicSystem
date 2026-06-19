#include "Form.h"

Form::Form() {
    form = "Nein";
}

Form::Form(FormEnum fm) {
    switch (fm) {
        case FormEnum::Ball:  form = "Ball";  break;
        case FormEnum::Wall: form = "Wall"; break;
        case FormEnum::Stream:   form = "Stream";   break;
        case FormEnum::Smoke: form = "Smoke"; break;
        case FormEnum::Zone: form = "Zone"; break;
        case FormEnum::Rod: form = "Rod"; break;
        default:            form = "Nein";  break;
    }
}

std::string Form::getForm() {
    return form;
}