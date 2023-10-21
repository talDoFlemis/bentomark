#ifndef Controller_H
#define Controller_H

#include "Model.h"
#include <initializer_list>
#include <vector>
#include <iostream>

// Controls the flow of models' execution.
class Controller {
private:
  unsigned int max_steps;
  std::vector<Model *> models;

public:
  // constructor
  Controller(unsigned int max, std::initializer_list<Model *> ms);

  // getters
  unsigned int get_max_steps() const;
  std::vector<Model *> &get_models();

  // setters
  void set_max_step(unsigned int max);

  double entry_error_handler();

  // TODO: execute all models.
  // ResultData run();
};

#endif // !DEBUG
