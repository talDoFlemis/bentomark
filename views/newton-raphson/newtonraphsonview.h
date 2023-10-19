#ifndef NEWTONRAPHSONVIEW_H
#define NEWTONRAPHSONVIEW_H

#include <QWidget>

namespace Ui {
class NewtonRaphsonView;
}

class NewtonRaphsonView : public QWidget
{
    Q_OBJECT

public:
    explicit NewtonRaphsonView(QWidget *parent = nullptr);
    ~NewtonRaphsonView();

private:
    Ui::NewtonRaphsonView *ui;
};

#endif // NEWTONRAPHSONVIEW_H
