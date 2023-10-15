#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDatabase>

#include "../entryview/entryview.h"
#include "../newton-raphson/newtonraphsonview.h"
#include "../modified-newton/modifiednewtonview.h"
#include "../secant/secantview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QFontDatabase::addApplicationFont(
      ":/fonts/assets/fonts/Amazdoomright-o1B0.ttf");

  EntryView *entryView = new EntryView(this);
  NewtonRaphsonView *newtonRaphsonView = new NewtonRaphsonView(this);
  ModifiedNewtonView *modifiedNewtonView = new ModifiedNewtonView(this);
  SecantView *secantView = new SecantView(this);

  ui->mainWidget->addWidget(entryView);
  ui->mainWidget->addWidget(newtonRaphsonView);
  ui->mainWidget->addWidget(modifiedNewtonView);
  ui->mainWidget->addWidget(secantView);

  connect(entryView, SIGNAL(statusBarTextChanged(QString)), this,
          SLOT(setStatusBarText(QString)));
  connect(entryView, SIGNAL(currentStackedWidgetChanged(int)), this,
          SLOT(setCurrentStackedWidget(int)));
}

void MainWindow::setStatusBarText(const QString &text) {
  ui->statusBar->showMessage(text);
}

void MainWindow::setCurrentStackedWidget(int index) {
  ui->mainWidget->setCurrentIndex(index);
}

MainWindow::~MainWindow() { delete ui; }
