#include <cmath>
#include "Model.h"

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

void Model::run() {
    int ittr = 0;
    this->results = std::vector<ModelResult*>();
    while (1) {
        this->updateNextStep();

        ModelResult* result = new ModelResult();
        result->root = this->nextStep;
        result->errorInterval = std::abs(this->nextStep - this->firstStep);
        result->errorFunction = std::abs(this->function->getValue(this->nextStep));

        this->results.push_back(result);

        if (result->errorFunction < this->thrFunction || 
            result->errorInterval < this->thrInterval || 
            ittr >= this->maxIttr) {
                this->root = this->nextStep;
                break;
        }

        this->updateValues();
        ittr++;
    }
}

double Model::getRoot() {
    return this->root;
}

std::vector<ModelResult*> Model::getResults() {
    return this->results;
}