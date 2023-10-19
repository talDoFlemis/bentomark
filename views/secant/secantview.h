#ifndef SECANTVIEW_H
#define SECANTVIEW_H

#include <QWidget>

namespace Ui {
class SecantView;
}

class SecantView : public QWidget
{
    Q_OBJECT

public:
    explicit SecantView(QWidget *parent = nullptr);
    ~SecantView();

private:
    Ui::SecantView *ui;
};

#endif // SECANTVIEW_H
