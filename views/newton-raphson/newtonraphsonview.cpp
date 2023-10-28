#include "newtonraphsonview.h"
#include "ui_newtonraphsonview.h"
#include "../../controllers/Newton.h"






NewtonRaphsonView::NewtonRaphsonView(QWidget *parent)
    : SharedMethodPageWidget("Newton RaphsoN", parent, "O Método de Newton-Raphson é como fazer uma suposição inicial de onde a resposta "
                                                       "pode estar ao tentar encontrar a raiz de uma função. "
                                                       "Então, ajustamos essa suposição com base na inclinação da curva, "
                                                       "aproximando-nos mais da solução a cada passo."){


}

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

std::vector<ModelResult*> NewtonRaphsonView::getResults(double a, double epsilon, double initialGuess, int maxSteps){
    Function* aux = new Function();
    double FirstGuess = setInitialGuess(&aux,a, 50);



    Newton *newton = new Newton();
    newton->setFunction(a);
    newton->setFirstStep(FirstGuess);
    newton->setMaxItterations(maxSteps);
    newton->setThrFunction(epsilon);
    newton->setThrInterval(epsilon);
    newton->run();
    return newton->getResults();
}

NewtonRaphsonView::~NewtonRaphsonView(){

}
