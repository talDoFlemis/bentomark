#include "bentomarkwidget.h"
#include "../../controllers/Newton.h"
#include "../../controllers/NewtonModified.h"
#include "../../controllers/Secant.h"
#include "ui_bentomarkwidget.h"
#include <iostream>
#include <qheaderview.h>
#include <qtablewidget.h>
#include <string>

BentomarkWidget::BentomarkWidget(int pos, double initialGuess, double epsilon,
                                 int maxSteps, QWidget *parent)
    : QWidget(parent), ui(new Ui::BentomarkWidget) {
  ui->setupUi(this);

  ui->guessBox->setValue(initialGuess);
  ui->epsilonBox->setValue(epsilon);
  ui->maxStepsBox->setValue(maxSteps);

  QFont logoFont("AmazDooMRight", 70);
  ui->title->setFont(logoFont);

  std::string title = "BentomarK " + std::to_string(pos);
  ui->title->setText(QString::fromStdString(title));

  setupTable();
  connect(ui->findRootBtn, SIGNAL(clicked()), this, SLOT(onFindRootClicked()));
}

void BentomarkWidget::onFindRootClicked() {
  ui->tableWidget->setRowCount(0);

  double a = ui->aBox->value();
  double epsilon = ui->epsilonBox->value();
  double maxSteps = ui->maxStepsBox->value();
  double initialGuess = ui->guessBox->value();

  ModelResult *newtonResults =
      getNewtonResults(a, initialGuess, epsilon, maxSteps);

  ModelResult *modifiedNewtonResults =
      getModifiedNewtonResults(a, initialGuess, epsilon, maxSteps);

  ModelResult *secantResults =
      getSecantResults(a, initialGuess, epsilon, maxSteps);

  populateTable(newtonResults, modifiedNewtonResults, secantResults);
}

ModelResult *BentomarkWidget::getNewtonResults(double a, double initialGuess,
                                               double epsilon, int maxSteps) {
  Newton *newton = new Newton();
  newton->setFunction(a);
  newton->setFirstStep(initialGuess);
  newton->setMaxItterations(maxSteps);
  newton->run();
  return newton->getResults();
}

ModelResult *BentomarkWidget::getModifiedNewtonResults(double a,
                                                       double initialGuess,
                                                       double epsilon,
                                                       int maxSteps) {
  NewtonModified *modified = new NewtonModified();
  modified->setFunction(a);
  modified->setFirstStep(initialGuess);
  modified->setMaxItterations(maxSteps);
  modified->run();
  return modified->getResults();
}

ModelResult *BentomarkWidget::getSecantResults(double a, double initialGuess,
                                               double epsilon, int maxSteps) {
  Secant *secant = new Secant();
  secant->setFunction(a);
  secant->setFirstStep(initialGuess);
  secant->setMaxItterations(maxSteps);
  secant->run();
  return secant->getResults();
}

void BentomarkWidget::setupTable() {
  ui->tableWidget->setColumnCount(9);
  QStringList horizontalHeaders = {
      "Newton xₖ",   "Newton |f(xₖ)|",   "Newton |xₖ+₁ - xₖ|",
      "Modified xₖ", "Modified |f(xₖ)|", "Modified |xₖ+₁ - xₖ|",
      "Secant xₖ",   "Secant |f(xₖ)|",   "Secant |xₖ+₁ - xₖ|"};

  ui->tableWidget->setHorizontalHeaderLabels(horizontalHeaders);
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void BentomarkWidget::populateTable(ModelResult *newtonResults,
                                    ModelResult *modifiedNewtonResults,
                                    ModelResult *secantResults) {
  ModelResult *newton = newtonResults;
  ModelResult *modified = modifiedNewtonResults;
  ModelResult *secant = secantResults;

  ui->tableWidget->insertRow(0);
  ui->tableWidget->setItem(0, 0,
                           new QTableWidgetItem(QString::number(newton->root)));
  ui->tableWidget->setItem(
      0, 1, new QTableWidgetItem(QString::number(newton->errorFunction)));
  ui->tableWidget->setItem(
      0, 2, new QTableWidgetItem(QString::number(newton->errorInterval)));

  ui->tableWidget->setItem(
      0, 3, new QTableWidgetItem(QString::number(modified->root)));
  ui->tableWidget->setItem(
      0, 4, new QTableWidgetItem(QString::number(modified->errorFunction)));
  ui->tableWidget->setItem(
      0, 5, new QTableWidgetItem(QString::number(modified->errorInterval)));

  ui->tableWidget->setItem(0, 6,
                           new QTableWidgetItem(QString::number(secant->root)));
  ui->tableWidget->setItem(
      0, 7, new QTableWidgetItem(QString::number(secant->errorFunction)));
  ui->tableWidget->setItem(
      0, 8, new QTableWidgetItem(QString::number(secant->errorInterval)));
}

BentomarkWidget::~BentomarkWidget() { delete ui; }
