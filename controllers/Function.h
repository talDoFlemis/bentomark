#ifndef Function_H
#define Function_H

class Function {
private:
    double constant;

public:
    Function();
    Function(double constant);
    void setConstant(double constant);
    double getConstant();

    double getValue(double displacement);
    double getDerivativeValue(double displacement);
};

#endif