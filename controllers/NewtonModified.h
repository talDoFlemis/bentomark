#include "Model.h"

#ifndef NewtonModified_H
#define NewtonModified_H

class NewtonModified : public Model {
private:
    double derivative;
public:
    NewtonModified();
    void setFirstStep(double step);
    void updateNextStep();
    void updateValues();
};

#endif