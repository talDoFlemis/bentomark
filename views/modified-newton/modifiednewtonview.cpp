#include "modifiednewtonview.h"
#include "../../controllers/NewtonModified.h"
#include "ui_modifiednewtonview.h"

ModifiedNewtonView::ModifiedNewtonView(QWidget *parent)
    : SharedMethodPageWidget("Modified NewtoN", parent) {}

std::vector<ModelResult *> ModifiedNewtonView::getResults(double a,
                                                          double epsilon,
                                                          double initialGuess,
                                                          int maxSteps) {
  NewtonModified *modified = new NewtonModified();
  modified->setFunction(a);
  modified->setFirstStep(initialGuess);
  modified->setMaxItterations(maxSteps);
  modified->setThrFunction(epsilon);
  modified->setThrInterval(epsilon);
  modified->run();
  return modified->getResults();
}

ModifiedNewtonView::~ModifiedNewtonView() {}
