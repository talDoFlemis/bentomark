#include "Function.h"
#include "ModelResult.h"

#ifndef Model_H
#define Model_H

class Model {
private:
    double root;
    double thrInterval;
    double thrFunction;
    int maxIttr;

public:
    ModelResult* results;
    Function* function;
    double firstStep;
    double nextStep;

    void setFunction(double constant);
    void setThrInterval(double thr);
    void setThrFunction(double thr);
    void setMaxItterations(int maxIttr);

    void run();
    double getRoot();
    ModelResult* getResults();
    virtual void updateNextStep() = 0;
    virtual void updateValues() = 0;
    virtual void setFirstStep(double step) = 0;
};

#endif