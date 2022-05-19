#include <vector>
#include "polinom.h"
#include "polynomial.h"
#include <iostream>

using namespace std;

int main() {
    vector<Var> value{(2,2),(3,1)};
    Polynomial(value,2);
}