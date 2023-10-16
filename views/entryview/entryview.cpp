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
}

void EntryView::onNewtonActionClicked() {
  emit statusBarTextChanged("Newton Raphson Method Selected");
  emit currentStackedWidgetChanged(1);
}

void EntryView::onModifiedActionClicked() {
  emit statusBarTextChanged("Modified Newton Method Selected");
  emit currentStackedWidgetChanged(2);
}

void EntryView::onSecantActionClicked() {
  emit statusBarTextChanged("Secant Method Selected");
  emit currentStackedWidgetChanged(3);
}

EntryView::~EntryView() { delete ui; }
