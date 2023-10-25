#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>


#include "Function.h"
#include "Model.h"
#include "ModelResult.h"
#include "Newton.h"
#include "NewtonModified.h"
#include "Secant.h"

void initializeModel(Model** model, double constant, double firstStep, double thrInterval, double thrFunction, int maxIttr) {
    (*model)->setFunction(constant);
    (*model)->setFirstStep(firstStep);
    (*model)->setThrInterval(thrInterval);
    (*model)->setThrFunction(thrFunction);
    (*model)->setMaxItterations(maxIttr);
}

double setInitialGuess(Function** foo, double a, int maxIttr) {
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




int main() {

    std::cout << ".______    _______ .__   __. .___________.   ______   .___    ___.      ___        .______       __  ___" << std::endl;
    std::cout << "|   _  \\ |   ____||  \\ |  | |           | /  __  \\  |   \\/   |     /   \\      |   _  \\    |  |/  /" << std::endl;
    std::cout << "|  |_)  | |  |__   |   \\|  | `---|  |----`|  |  |  |  |  \\  /  |    /  ^  \\     |  |_)  |    |  '  /" << std::endl;
    std::cout << "|   _  <  |   __|  |  . `   |     |  |     |  |  |  |  |  |\\/|  |   /  /_\\  \\   |      /     |    <" << std::endl;
    std::cout << "|  |_)  | |  |____ |  |\\   |     |  |     |  `--'  |  |  |   |  |  /  _____  \\   |  |\\\\----.|  .  \\" << std::endl;
    std::cout << "|______/  |_______||__| \\__|     |__|     \\______/   |__|   |__| /__/     \\__\\ | _| `._____||__|\\__\\" << std::endl;


    std::cout << std::endl;
    std::cout << std::endl;



    std::cout << std::fixed << std::showpoint;
    

    int n;
    std::cout << "Entre o número de valores para a: ";
    std::cin >> n;

    std::cout << std::endl;

    double a[n];
    double x[n];
    Function* aux = new Function();
    for (int i = 0; i < n; i++) {
        std::cout << "Entre o valor de a" << i+1 << ": ";
        std::cin >> a[i];
        x[i] = setInitialGuess(&aux, a[i], 50);
    }

   


    bool setInitialGuess;
    std::cout << "Deseja inserir o d0 ou utilizar um fornecido pelo sistema? (1: inserir  || 0: fornecido): ";
    std::cin >> setInitialGuess;
    std::cout << std::endl;
    
    double initialGuess;
    if(setInitialGuess){
        std::cout << "Entre o valor do d0: ";
        std::cin >> initialGuess;
    }
    std::cout << std::endl;


    std::string setEpslon;
    double epsilon1;
    double epsilon2;
    std::cin.ignore();
    while (true) {
   
        std::cout << "Você deseja utilizar epslon 1, 2 ou ambos? [E1 || E2 || A]: ";
        std::getline(std::cin, setEpslon);
        std::cout << std::endl;

        if (setEpslon == "E1"){
            std::cout << "Entre o epslon 1: ";
            std::cin >> epsilon1;
            std::cout << std::endl;

           epsilon2 = std::nan("");

            break;
        } else if (setEpslon == "E2"){
            std::cout << "Entre o epslon 2: ";
            std::cin >> epsilon2;
            std::cout << std::endl;

            epsilon1 = std::nan("");

            break;
        }
        
        else if (setEpslon == "A"){
            std::cout << "Entre o epslon 1: ";
            std::cin >> epsilon1;
            std::cout << std::endl;

            std::cout << "Entre o epslon 2: ";
            std::cin >> epsilon2;
            std::cout << std::endl;

            break;
        }
        else {
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    }
    

    double steps;
    std::cout << "Entre a quantidade máxima de passos que devem ser realizadas: ";
    std::cin >> steps;
    std::cout << std::endl;

    bool setView;
    std::cout << "Deseja visualizar todos os passos? (1: sim  || 0: não): ";
    std::cin >> setView;
    std::cout << std::endl;


    Model* models[3];
    models[0] = new Secant();
    models[1] = new Newton();
    models[2] = new NewtonModified();

    if (!setView)
    {
       
        std::cout << std::endl;

    }
    

    for (int i = 0; i < n; i++) {

        std::cout << std::setprecision(3);
        std::cout << std::endl;
        std::cout << "============================================================"<<std::endl;
        std::cout << std::endl;
        std::cout << "Calculo para a = " << a[i] << "  |  " << "d0 = "<< (setInitialGuess ? initialGuess : x[i]) << "  |  " << "E1 = " << std::scientific << epsilon1 << "  E2 = " << std::scientific << epsilon2 << std::endl;
        std::cout << std::setprecision(6);
        for (int j = 0; j < 3; j++) {
            
           

            if (setInitialGuess){
                 initializeModel(&models[j],a[i],initialGuess,epsilon1,epsilon2,steps);
            }
            else{
                 initializeModel(&models[j],a[i],x[i],epsilon1,epsilon2,steps);
            }
           
            models[j]->run();

            std::vector<ModelResult*>* results = models[j]->results;
            int k = 0;
            if(setView){

                switch (j)
                    {
                    case 0:
                        std::cout << std::endl;
                        std::cout << "            ================================ Método da Secante ===============================";
                        std::cout << std::endl;
                        break;
                    case 1:
                        std::cout << std::endl;
                        std::cout << "            ======================== Método de Newton-Raphson ================================";
                        std::cout << std::endl;
                        break;
                    case 2:
                        std::cout << std::endl;
                        std::cout << "            ============================ Método de Newton Modificado =========================";
                        std::cout << std::endl;
                        break;

                    
                    default:
                        break;
                    }



                 for (const ModelResult* result : *results) {

                    std::cout << "K:" << k << "    Root: " << result->root << "||   Error Interval: " << result->errorInterval  << "||  Error Function: " << result->errorFunction << "||" << std::endl;
                    k++;

                    if (std::isinf(result->root) ){
                        break;
                    }
                    


                }
                if( std::isnan(results->back()->root) ){
                    std::cout << "Raiz = O método não converge para o número de passos ou valor inicial setado";
                }
                else{
                    std::cout << "Raiz = " << results->back()->root;
                    std::cout << std::endl;
                }

            }

            else {
                if (j == 0){
                    std::cout << "|   Método de Newton-Raphson    |       Método da Secante       |  Método de Newton Modificado  |" << std::endl;
                     std::cout << "|   raíz     erro1      erro2   |   raíz     erro1      erro2   |   raíz     erro1      erro2   |" << std::endl;
                }
                std::cout << "  " << results->back()->root << "  " << results->back()->errorInterval << "  " << results->back()->errorFunction << "  |"; 
            }


        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}