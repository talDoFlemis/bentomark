#include "mainwindow.h"
#include "../entryview/entryview.h"
#include "ui_mainwindow.h"
#include <QFontDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QFontDatabase::addApplicationFont(":/fonts/assets/fonts/Amazdoomright-o1B0.ttf");


  EntryView *entryView = new EntryView(this);
  ui->mainWidget->addWidget(entryView);
  connect(entryView, SIGNAL(statusBarTextChanged(QString)), this,
          SLOT(setStatusBarText(QString)));
}

void MainWindow::setStatusBarText(const QString &text) {
  ui->statusBar->showMessage(text);
}

MainWindow::~MainWindow() { delete ui; }
