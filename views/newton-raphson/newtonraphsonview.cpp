#include "newtonraphsonview.h"
#include "ui_newtonraphsonview.h"

NewtonRaphsonView::NewtonRaphsonView(QWidget *parent)
    : QWidget(parent), ui(new Ui::NewtonRaphsonView) {
  ui->setupUi(this);
  QFont logoFont("AmazDooMRight", 100);
  ui->title->setFont(logoFont);
}

NewtonRaphsonView::~NewtonRaphsonView() { delete ui; }
