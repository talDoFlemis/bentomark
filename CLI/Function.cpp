#include <cmath>
#include "Function.h"

Function::Function() {}

Function::Function(double constant) {
    this->constant = constant;
}

void Function::setConstant(double constant) {
    this->constant = constant;
}

double Function::getConstant() {
    return this->constant;
}

double Function::getValue(double displacement) {
    return (this->constant) * exp(displacement) - 4 * pow(displacement, 2);
}

double Function::getDerivativeValue(double displacement) {
    return (this->constant) * exp(displacement) - 8 * displacement;
}