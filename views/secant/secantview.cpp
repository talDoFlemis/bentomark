#include "secantview.h"
#include "../../controllers/Secant.h"
#include "ui_secantview.h"

SecantView::SecantView(QWidget *parent)
    : SharedMethodPageWidget("SecanT", parent) {}










inline double setInitialGuess(Function** foo, double a, int maxIttr) {
    (*foo)->setConstant(a);

    int idx = 1;
    bool signSwapped = false;
    double previousValue = (*foo)->getValue(0);
    double nextValue;

    while (idx < maxIttr && signSwapped == false) {
        nextValue = (*foo)->getValue(0 + idx * 0.01);
        if (nextValue * previousValue < 0) {
            return 0 + idx * 0.1;
        }
        previousValue = nextValue;
        idx++;
    }
    return 0 + idx * 0.1;
}





std::vector<ModelResult *> SecantView::getResults(double a, double epsilon,
                                                  double initialGuess,
                                                  int maxSteps) {

    Function* aux = new Function();
    double FirstGuess = setInitialGuess(&aux,a, 50);
    Secant *secant = new Secant();
    secant->setFunction(a);
    secant->setFirstStep(FirstGuess);
    secant->setMaxItterations(maxSteps);
    secant->setThrFunction(epsilon);
    secant->setThrInterval(epsilon);
    secant->run();
    return secant->getResults();
}

SecantView::~SecantView() {}
