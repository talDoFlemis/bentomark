#include "Model.h"

#ifndef Secant_H
#define Secant_H

class Secant : public Model {
private:
    double previousStep;

public:
    Secant();
    void setFirstStep(double step);
    void updateNextStep();
    void updateValues();
};

#endif