#ifndef ENTRYVIEW_H
#define ENTRYVIEW_H

#include <QWidget>

namespace Ui {
class EntryView;
}

class EntryView : public QWidget
{
    Q_OBJECT

public:
    explicit EntryView(QWidget *parent = nullptr);
    ~EntryView();

public slots:
  void onNewtonActionClicked();
  void onModifiedActionClicked();
  void onSecantActionClicked();
  void onClashActionClicked();

signals:
    void statusBarTextChanged(const QString &text);
    void currentStackedWidgetChanged(int index);


private:
    Ui::EntryView *ui;
};

#endif // ENTRYVIEW_H
