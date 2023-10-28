#include "modifiednewtonview.h"
#include "../../controllers/NewtonModified.h"
#include "ui_modifiednewtonview.h"

ModifiedNewtonView::ModifiedNewtonView(QWidget *parent)
    : SharedMethodPageWidget("Modified NewtoN", parent) {}


//double setInitialGuess(Function** foo, double a, int maxIttr) {
//    (*foo)->setConstant(a);

//    int idx = 1;
//    bool signSwapped = false;
//    double previousValue = (*foo)->getValue(0);
//    double nextValue;

//    while (idx < maxIttr && signSwapped == false) {
//        nextValue = (*foo)->getValue(0 + idx * 0.01);
//        if (nextValue * previousValue < 0) {
//            return 0 + idx * 0.1;
//        }
//        previousValue = nextValue;
//        idx++;
//    }
//    return 0 + idx * 0.1;
//}

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
std::vector<ModelResult *> ModifiedNewtonView::getResults(double a,
                                                          double epsilon,
                                                          double initialGuess,
                                                          int maxSteps) {


    Function* aux = new Function();
    double FirstGuess = setInitialGuess(&aux,a, 50);





    NewtonModified *modified = new NewtonModified();
    modified->setFunction(a);
    modified->setFirstStep(FirstGuess);
    modified->setMaxItterations(maxSteps);
    modified->setThrFunction(epsilon);
    modified->setThrInterval(epsilon);
    modified->run();
    return modified->getResults();
}

ModifiedNewtonView::~ModifiedNewtonView() {}
