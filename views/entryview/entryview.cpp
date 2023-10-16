#include "entryview.h"
#include "ui_entryview.h"

EntryView::EntryView(QWidget *parent) : QWidget(parent), ui(new Ui::EntryView) {
  ui->setupUi(this);

  QFont logoFont("AmazDooMRight", 100);
  ui->title->setFont(logoFont);

  parent->setWindowTitle("Welcome • Bentomark");

  connect(ui->newtonAction, SIGNAL(clicked()), this,
          SLOT(onNewtonActionClicked()));
  connect(ui->modifiedAction, SIGNAL(clicked()), this,
          SLOT(onModifiedActionClicked()));
  connect(ui->secantAction, SIGNAL(clicked()), this,
          SLOT(onSecantActionClicked()));

  connect(ui->clashAction, SIGNAL(clicked()), this,
          SLOT(onClashActionClicked()));
}

void EntryView::onNewtonActionClicked() {
  this->parentWidget()->setWindowTitle("Newton • Bentomark");
  emit statusBarTextChanged("Newton Raphson Method Selected");
  emit currentStackedWidgetChanged(1);
}

void EntryView::onModifiedActionClicked() {
  this->parentWidget()->setWindowTitle("Modified Newton • Bentomark");
  emit statusBarTextChanged("Modified Newton Method Selected");
  emit currentStackedWidgetChanged(2);
}

void EntryView::onSecantActionClicked() {
  this->parentWidget()->setWindowTitle("Secant • Bentomark");
  emit statusBarTextChanged("Secant Method Selected");
  emit currentStackedWidgetChanged(3);
}

void EntryView::onClashActionClicked() {
  this->parentWidget()->setWindowTitle("Clash of Methods • Bentomark");
  emit statusBarTextChanged("Clash Method Selected");
  emit currentStackedWidgetChanged(4);
}

EntryView::~EntryView() { delete ui; }
