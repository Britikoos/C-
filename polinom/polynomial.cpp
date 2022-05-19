#include "polynomial.h"

Polynomial::Polynomial(std::vector<Var> vars, int size)
        : vars_(vars), size_(size) {};

Polynomial::Polynomial(const Polynomial &p)
        : vars_(p.vars_), size_(p.size_) {};

std::vector<Var> Polynomial::get_vars() const {
    return this->vars_;
};

int Polynomial::get_size() const {
    return this->size_;
};
Polynomial& Polynomial::operator=(const Polynomial& p) {
    vars_ = p.vars_;
    size_ = p.size_;
    return *this;
};

bool Polynomial::operator==(const Polynomial& p) {
    if (vars_ == p.vars_) {
        return true;
    };
    return false;
};

bool Polynomial::operator!=(const Polynomial& p) {
    if (vars_ == p.vars_) {
        return false;
    };
    return true;
};

Var Polynomial::operator[](int index) const {
    return this->vars_[index];
};

Polynomial& Polynomial::operator+(const Polynomial& p) {
    Polynomial pol = Polynomial(vars_, size_);
    int size = size_;
    if (size_ > p.size_) {
        size = p.get_size();
    };
    for (int i = 0; i < size; i++) {
        pol.vars_[i].set_coeff(vars_[i].get_coeff() + p.get_vars()[i].get_coeff());
    };
};

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
    int size = p.get_size();
    for (int i = 0; i < size; i++) {
        float coeff = p[i].get_coeff();
        float exp = p[i].get_exp();
        os << coeff << "x" << i+1 << "^" << exp;
    };
    return os;
}