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
  ui->title->setText("Newton");
  emit statusBarTextChanged("Modified Newton Method Selected");
}

void EntryView::onModifiedActionClicked() {
  ui->title->setText("Modified Newton");
}

void EntryView::onSecantActionClicked() { ui->title->setText("Secant"); }

EntryView::~EntryView() { delete ui; }
