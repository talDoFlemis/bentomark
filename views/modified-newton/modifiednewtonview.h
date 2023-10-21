#ifndef MODIFIEDNEWTONVIEW_H
#define MODIFIEDNEWTONVIEW_H

#include <QWidget>
#include "../../controllers/ModelResult.h"
#include "../shared/sharedmethodpagewidget.h"

namespace Ui {
class ModifiedNewtonView;
}

class ModifiedNewtonView : public SharedMethodPageWidget
{
    Q_OBJECT

public:
    explicit ModifiedNewtonView(QWidget *parent = nullptr);
    std::vector<ModelResult*> getResults(double a, double epsilon, double initialGuess, int maxSteps) override;
    ~ModifiedNewtonView();
};

#endif // MODIFIEDNEWTONVIEW_H
