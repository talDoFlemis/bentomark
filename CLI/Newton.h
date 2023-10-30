#include "Model.h"

#ifndef Newton_H
#define Newton_H

class Newton : public Model {
public:
    Newton();
    void setFirstStep(double step);
    void updateNextStep();
    void updateValues();
};

#endif