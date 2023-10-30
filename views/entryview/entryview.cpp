#include "entryview.h"
#include "ui_entryview.h"

EntryView::EntryView(QWidget *parent) : QWidget(parent), ui(new Ui::EntryView) {
  ui->setupUi(this);

  QFont logoFont("AmazDooMRight", 100);
  ui->title->setFont(logoFont);

  parent->setWindowTitle("Bentomark");

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
  emit currentStackedWidgetChanged(1);
}

void EntryView::onModifiedActionClicked() {
  emit currentStackedWidgetChanged(2);
}

void EntryView::onSecantActionClicked() {
  emit currentStackedWidgetChanged(3);
}

void EntryView::onClashActionClicked() {
  emit currentStackedWidgetChanged(4);
}

EntryView::~EntryView() { delete ui; }

void EntryView::on_pushButton_clicked()
{
  emit currentStackedWidgetChanged(5);
}

