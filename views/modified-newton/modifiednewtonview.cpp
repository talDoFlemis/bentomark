#include "modifiednewtonview.h"
#include "ui_modifiednewtonview.h"

ModifiedNewtonView::ModifiedNewtonView(QWidget *parent)
    : QWidget(parent), ui(new Ui::ModifiedNewtonView) {
  ui->setupUi(this);
  QFont logoFont("AmazDooMRight", 100);
  ui->title->setFont(logoFont);
}

ModifiedNewtonView::~ModifiedNewtonView() { delete ui; }
