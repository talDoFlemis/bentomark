#include "secantview.h"
#include "ui_secantview.h"

SecantView::SecantView(QWidget *parent)
    : QWidget(parent), ui(new Ui::SecantView) {
  ui->setupUi(this);
  QFont logoFont("AmazDooMRight", 100);
  ui->title->setFont(logoFont);
}

SecantView::~SecantView() { delete ui; }
