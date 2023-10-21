#ifndef NEWTONRAPHSONVIEW_H
#define NEWTONRAPHSONVIEW_H

#include <QWidget>
#include "../../controllers/ModelResult.h"
#include "../shared/sharedmethodpagewidget.h"

namespace Ui {
class NewtonRaphsonView;
}

class NewtonRaphsonView : public SharedMethodPageWidget
{
    Q_OBJECT

public:
    explicit NewtonRaphsonView(QWidget *parent = nullptr);
    std::vector<ModelResult*> getResults(double a, double epsilon, double initialGuess, int maxSteps) override;
    ~NewtonRaphsonView();
};

#endif // NEWTONRAPHSONVIEW_H
