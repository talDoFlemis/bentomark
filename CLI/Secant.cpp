#include "Secant.h"

Secant::Secant(){}

void Secant::setFirstStep(double step) {
    this->previousStep = step;
    this->firstStep = step + 2;
}

void Secant::updateNextStep() {
    this->nextStep = this->firstStep - this->function->getValue(this->firstStep) / (this->function->getValue(this->firstStep) - this->function->getValue(previousStep)) * (this->firstStep - this->previousStep);
}

void Secant::updateValues() {
    this->previousStep = this->firstStep;
    this->firstStep = this->nextStep;
}