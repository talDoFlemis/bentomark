#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>

namespace Ui {
class AboutView;
}

class AboutView : public QWidget
{
    Q_OBJECT

public:
    explicit AboutView(QWidget *parent = nullptr);
    ~AboutView();

private:
    Ui::AboutView *ui;
};

#endif // ABOUT_H
