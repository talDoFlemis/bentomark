#include "secantview.h"
#include "../../controllers/Secant.h"
#include "ui_secantview.h"

SecantView::SecantView(QWidget *parent)
    : SharedMethodPageWidget("SecanT", parent) {}

std::vector<ModelResult *> SecantView::getResults(double a, double epsilon,
                                                  double initialGuess,
                                                  int maxSteps) {
  Secant *secant = new Secant();
  secant->setFunction(a);
  secant->setFirstStep(initialGuess);
  secant->setMaxItterations(maxSteps);
  secant->setThrFunction(epsilon);
  secant->setThrInterval(epsilon);
  secant->run();
  return secant->getResults();
}

SecantView::~SecantView() {}
