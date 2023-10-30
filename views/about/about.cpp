#include "about.h"
#include "ui_about.h"

AboutView::AboutView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutView)
{
    ui->setupUi(this);

    // Crie a fonte com o nome "AmazDooMRight" e tamanho 80
    QFont font("AmazDooMRight");
    font.setPointSize(80);

    // Aplique a fonte ao widget ou a um QLabel, por exemplo
    ui->title->setFont(font);
}

AboutView::~AboutView()
{
    delete ui;
}
