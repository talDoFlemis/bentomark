#ifndef SHAREDMETHODPAGEWIDGET_H
#define SHAREDMETHODPAGEWIDGET_H

#include <QWidget>
#include "../../controllers/ModelResult.h"

namespace Ui {
class SharedMethodPageWidget;
}

class SharedMethodPageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SharedMethodPageWidget(std::string title, QWidget *parent = nullptr);
    virtual std::vector<ModelResult*> getResults(double a, double epsilon, double initialGuess, int maxSteps) = 0;
    ~SharedMethodPageWidget();

private slots:
    void on_findRootBtn_clicked();

private:
    Ui::SharedMethodPageWidget *ui;
    void setupTable();
    void populateTable(std::vector<ModelResult*> results);
};

#endif // SHAREDMETHODPAGEWIDGET_H
