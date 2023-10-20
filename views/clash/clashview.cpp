#include "clashview.h"
#include "ui_clashview.h"
#include "bentomarkwidget.h"

ClashView::ClashView(QWidget *parent) : QWidget(parent), ui(new Ui::ClashView) {
  ui->setupUi(this);
  setupFonts();
  populateClashList();
}

void ClashView::setupFonts() {
  QFont logoFont("AmazDooMRight", 80);
  QFont subtitleFont("AmazDooMRight", 70);
  ui->title->setFont(logoFont);
  ui->initialLabel->setFont(subtitleFont);
}

void ClashView::populateClashList() {
  double initialGuess = ui->defaultGuess->value();
  double maxSteps = ui->defaultSteps->value();
  double epsilon = ui->defaultEpsilon->value();

  for (size_t i = 0; i < ui->numberOfInputs->value(); i++) {
      BentomarkWidget* bento = new BentomarkWidget(i + 1, initialGuess, epsilon, maxSteps);
        ui->tablesLayout->addWidget(bento);
  }
}

ClashView::~ClashView() { delete ui; }

void ClashView::on_numberOfInputs_valueChanged(int arg1)
{
  QLayoutItem* child;
  while ((child = ui->tablesLayout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            delete child->widget();
        }
        delete child;
  }
  populateClashList();
}

