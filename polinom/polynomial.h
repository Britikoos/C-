
#ifndef POLINOM_POLYNOMIAL_H
#define POLINOM_POLYNOMIAL_H

#include <vector>
#include "polinom.h"
#include <iostream>

class Polynomial {
private:
    std::vector<Var> vars_;
    int size_;

public:
    explicit Polynomial(std::vector<Var> vars, int size);

    Polynomial(const Polynomial& p);

    ~Polynomial() {}

    std::vector<Var> get_vars() const ;

    int get_size() const ;

    Polynomial& operator=(const Polynomial& p);

    bool operator==(const Polynomial& p);

    bool operator!=(const Polynomial& p);

    Var operator[](int index) const;

    Polynomial& operator+(const Polynomial& p);

    Polynomial& operator-(const Polynomial& p);

    Polynomial& operator+=(const Polynomial& p) ;
    Polynomial& operator-=(const Polynomial& p);
    Polynomial& operator*(const Polynomial& p);
    Polynomial& operator/(const Polynomial& p) ;
    Polynomial& operator*=(const Polynomial& p) ;

    Polynomial& operator/=(const Polynomial& p);

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);

    friend std::istream& operator>>(std::istream& is, const Polynomial& p);
};



#endif //POLINOM_POLYNOMIAL_H
