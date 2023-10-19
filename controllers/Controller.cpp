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
