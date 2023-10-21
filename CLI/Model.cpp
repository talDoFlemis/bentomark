#include <cmath>
#include "Model.h"
#include "Controller.h"

void Model::setFunction(double constant) {
    this->function = new Function(constant);
}

void Model::setThrInterval(double thr) {
    this->thrInterval = thr;
}

void Model::setThrFunction(double thr) {
    this->thrFunction = thr;
}

void Model::setMaxItterations(int maxIttr) {
    this->maxIttr = maxIttr;
}

void Model::run(Controller &controller) {
    int ittr = 0;
    this->results = new ModelResult;
    while (1) {
        this->updateNextStep();

        this->results->root = this->nextStep;
        this->results->errorInterval = std::abs(this->nextStep - this->firstStep);
        this->results->errorFunction = std::abs(this->function->getValue(this->nextStep));

        if (this->results->errorFunction < this->thrFunction || 
            this->results->errorInterval < this->thrInterval || 
            ittr >= this->maxIttr) {
                this->root = this->nextStep;
                 controller.checkConvergence(this, ittr);
                break;
        }

        this->updateValues();
        ittr++;
    }
}

double Model::getRoot() {
    return this->root;
}

ModelResult* Model::getResults() {
    return this->results;
}