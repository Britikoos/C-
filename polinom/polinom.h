
#ifndef POLINOM_POLINOM_H
#define POLINOM_POLINOM_H

class Var {
private:
    float coeff_;
    float exp_;

public:
    Var(float coeff, float exp);


    ~Var() {};

    float get_coeff() const;

    void set_coeff(float coeff) ;

    float get_exp() const;
};
#endif //POLINOM_POLINOM_H
