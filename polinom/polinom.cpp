#include "polinom.h"

Var::Var(float coeff, float exp)
        : coeff_(coeff), exp_(exp) {}

float Var::get_coeff() const {
    return this->coeff_;
}

void Var::set_coeff(float coeff) {
    coeff_ = coeff;
}

float Var::get_exp() const {
    return this->exp_;
}