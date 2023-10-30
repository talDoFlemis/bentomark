#ifndef CLASHVIEW_H
#define CLASHVIEW_H

#include <QWidget>

namespace Ui {
class ClashView;
}

class ClashView : public QWidget
{
    Q_OBJECT

public:
    explicit ClashView(QWidget *parent = nullptr);
    ~ClashView();

private slots:
    void on_numberOfInputs_valueChanged(int arg1);

private:
    Ui::ClashView *ui;
    void setupFonts();
    void populateClashList();
};

#endif // CLASHVIEW_H
