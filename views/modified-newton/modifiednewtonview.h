#ifndef MODIFIEDNEWTONVIEW_H
#define MODIFIEDNEWTONVIEW_H

#include <QWidget>

namespace Ui {
class ModifiedNewtonView;
}

class ModifiedNewtonView : public QWidget
{
    Q_OBJECT

public:
    explicit ModifiedNewtonView(QWidget *parent = nullptr);
    ~ModifiedNewtonView();

private:
    Ui::ModifiedNewtonView *ui;
};

#endif // MODIFIEDNEWTONVIEW_H
