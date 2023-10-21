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
  double maxSteps = ui->maxStepsBox->value() - 1;
  double initialGuess = ui->guessBox->value();

  vector<ModelResult *> newtonResults =
      getNewtonResults(a, initialGuess, epsilon, maxSteps);

  vector<ModelResult *> modifiedNewtonResults =
      getModifiedNewtonResults(a, initialGuess, epsilon, maxSteps);

  vector<ModelResult *> secantResults =
      getSecantResults(a, initialGuess, epsilon, maxSteps);

  populateTable(newtonResults, modifiedNewtonResults, secantResults);
}

vector<ModelResult *> BentomarkWidget::getNewtonResults(double a,
                                                        double initialGuess,
                                                        double epsilon,
                                                        int maxSteps) {
  Newton *newton = new Newton();
  newton->setFunction(a);
  newton->setFirstStep(initialGuess);
  newton->setMaxItterations(maxSteps);
  newton->setThrFunction(epsilon);
  newton->setThrInterval(epsilon);
  newton->run();
  return newton->getResults();
}

vector<ModelResult *>
BentomarkWidget::getModifiedNewtonResults(double a, double initialGuess,
                                          double epsilon, int maxSteps) {
  NewtonModified *modified = new NewtonModified();
  modified->setFunction(a);
  modified->setFirstStep(initialGuess);
  modified->setMaxItterations(maxSteps);
  modified->setThrFunction(epsilon);
  modified->setThrInterval(epsilon);
  modified->run();
  return modified->getResults();
}

vector<ModelResult *> BentomarkWidget::getSecantResults(double a,
                                                        double initialGuess,
                                                        double epsilon,
                                                        int maxSteps) {
  Secant *secant = new Secant();
  secant->setFunction(a);
  secant->setFirstStep(initialGuess);
  secant->setMaxItterations(maxSteps);
  secant->setThrFunction(epsilon);
  secant->setThrInterval(epsilon);
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

void BentomarkWidget::populateTable(vector<ModelResult *> newtonResults,
                                    vector<ModelResult *> modifiedNewtonResults,
                                    vector<ModelResult *> secantResults) {
  int newtonSize = newtonResults.size();
  int modifiedSize = modifiedNewtonResults.size();
  int secantSize = secantResults.size();

  int max = std::max(newtonSize, std::max(modifiedSize, secantSize));

  for (int i = 0; i < max; i++) {
    ModelResult *newton = newtonResults[i];
    ModelResult *modified = modifiedNewtonResults[i];
    ModelResult *secant = secantResults[i];

    ui->tableWidget->insertRow(i);

    if (i >= newtonSize) {
      ui->tableWidget->setItem(i, 0, new QTableWidgetItem(""));
      ui->tableWidget->setItem(i, 1, new QTableWidgetItem(""));
      ui->tableWidget->setItem(i, 2, new QTableWidgetItem(""));
    } else {
      ui->tableWidget->setItem(
          i, 0, new QTableWidgetItem(QString::number(newton->root)));
      ui->tableWidget->setItem(
          i, 1, new QTableWidgetItem(QString::number(newton->errorFunction)));
      ui->tableWidget->setItem(
          i, 2, new QTableWidgetItem(QString::number(newton->errorInterval)));
    }

    if (i >= modifiedSize) {
      ui->tableWidget->setItem(i, 3, new QTableWidgetItem(""));
      ui->tableWidget->setItem(i, 4, new QTableWidgetItem(""));
      ui->tableWidget->setItem(i, 5, new QTableWidgetItem(""));
    } else {
      ui->tableWidget->setItem(
          i, 3, new QTableWidgetItem(QString::number(modified->root)));
      ui->tableWidget->setItem(
          i, 4, new QTableWidgetItem(QString::number(modified->errorFunction)));
      ui->tableWidget->setItem(
          i, 5, new QTableWidgetItem(QString::number(modified->errorInterval)));
    }

    if (i >= secantSize) {
      ui->tableWidget->setItem(i, 6, new QTableWidgetItem(""));
      ui->tableWidget->setItem(i, 7, new QTableWidgetItem(""));
      ui->tableWidget->setItem(i, 8, new QTableWidgetItem(""));
    } else {
      ui->tableWidget->setItem(
          i, 6, new QTableWidgetItem(QString::number(secant->root)));
      ui->tableWidget->setItem(
          i, 7, new QTableWidgetItem(QString::number(secant->errorFunction)));
      ui->tableWidget->setItem(
          i, 8, new QTableWidgetItem(QString::number(secant->errorInterval)));
    }
  }
}

BentomarkWidget::~BentomarkWidget() { delete ui; }
