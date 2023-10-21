#include "newtonraphsonview.h"
#include "ui_newtonraphsonview.h"
#include "../../controllers/Newton.h"

NewtonRaphsonView::NewtonRaphsonView(QWidget *parent)
    : SharedMethodPageWidget("Newton RaphsoN", parent){

}

std::vector<ModelResult*> NewtonRaphsonView::getResults(double a, double epsilon, double initialGuess, int maxSteps){
    Newton *newton = new Newton();
    newton->setFunction(a);
    newton->setFirstStep(initialGuess);
    newton->setMaxItterations(maxSteps);
    newton->setThrFunction(epsilon);
    newton->setThrInterval(epsilon);
    newton->run();
    return newton->getResults();
}

NewtonRaphsonView::~NewtonRaphsonView(){

}
