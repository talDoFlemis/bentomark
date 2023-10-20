#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

public slots:
  void setStatusBarText(const QString &text);
  void setCurrentStackedWidget(int index);

private slots:
  void onActionHomeTriggered();
  void onActionNewtonTriggered();
  void onActionModifiedTriggered();
  void onActionSecantTriggered();
  void onActionClashTriggered();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
