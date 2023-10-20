#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDatabase>

#include "../clash/clashview.h"
#include "../entryview/entryview.h"
#include "../modified-newton/modifiednewtonview.h"
#include "../newton-raphson/newtonraphsonview.h"
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
  ClashView *clashView = new ClashView(this);

  ui->mainWidget->addWidget(entryView);
  ui->mainWidget->addWidget(newtonRaphsonView);
  ui->mainWidget->addWidget(modifiedNewtonView);
  ui->mainWidget->addWidget(secantView);
  ui->mainWidget->addWidget(clashView);

  connect(entryView, SIGNAL(statusBarTextChanged(QString)), this,
          SLOT(setStatusBarText(QString)));
  connect(entryView, SIGNAL(currentStackedWidgetChanged(int)), this,
          SLOT(setCurrentStackedWidget(int)));

  connect(ui->actionHome, SIGNAL(triggered()), this,
          SLOT(onActionHomeTriggered()));
  connect(ui->actionNewton_Raphson, SIGNAL(triggered()), this,
          SLOT(onActionNewtonTriggered()));
  connect(ui->actionModified_Newton, SIGNAL(triggered()), this,
          SLOT(onActionModifiedTriggered()));
  connect(ui->actionSecant, SIGNAL(triggered()), this,
          SLOT(onActionSecantTriggered()));
  connect(ui->actionClash_of_Methods, SIGNAL(triggered()), this,
          SLOT(onActionClashTriggered()));
}

void MainWindow::setStatusBarText(const QString &text) {
  ui->statusBar->showMessage(text);
}

void MainWindow::setCurrentStackedWidget(int index) {
  ui->mainWidget->setCurrentIndex(index);
}

void MainWindow::onActionHomeTriggered() { ui->mainWidget->setCurrentIndex(0); }

void MainWindow::onActionNewtonTriggered() {
  ui->mainWidget->setCurrentIndex(1);
};
void MainWindow::onActionModifiedTriggered() {
  ui->mainWidget->setCurrentIndex(2);
};

void MainWindow::onActionSecantTriggered() {
  ui->mainWidget->setCurrentIndex(3);
};
void MainWindow::onActionClashTriggered() {
  ui->mainWidget->setCurrentIndex(4);
};

MainWindow::~MainWindow() { delete ui; }
