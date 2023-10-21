#ifndef SECANTVIEW_H
#define SECANTVIEW_H

#include <QWidget>
#include "../../controllers/ModelResult.h"
#include "../shared/sharedmethodpagewidget.h"

namespace Ui {
class SecantView;
}

class SecantView : public SharedMethodPageWidget
{
    Q_OBJECT

public:
    explicit SecantView(QWidget *parent = nullptr);
    std::vector<ModelResult*> getResults(double a, double epsilon, double initialGuess, int maxSteps) override;
    ~SecantView();

private:
    Ui::SecantView *ui;
};

#endif // SECANTVIEW_H
