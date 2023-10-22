#include "Controller.h"
#include <initializer_list>
#include <vector>

// constructor
#include <iostream>
#include "Controller.h"
#include <initializer_list>
#include <vector>

// constructor
Controller::Controller(unsigned int max, std::initializer_list<Model *> ms)
    : max_steps{max}, models{std::vector<Model *>(ms)} {}

// getters
unsigned int Controller::get_max_steps() const { return max_steps; }
std::vector<Model *> &Controller::get_models() { return models; }

// setters
void Controller::set_max_step(unsigned int max) { max_steps = max; }
void Controller::checkConvergence(Model *model, int iterations) const {
    if(iterations > max_steps){
        std::cout << "Warning: O número de iterações atingiu o limite máximo." << std::endl;
    }
}