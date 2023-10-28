#include "sharedmethodpagewidget.h"
#include "ui_sharedmethodpagewidget.h"
#include "../../controllers/ModelResult.h"
using namespace std;

SharedMethodPageWidget::SharedMethodPageWidget(std::string title, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SharedMethodPageWidget)
{
    ui->setupUi(this);
    QFont logoFont("AmazDooMRight", 80);
    ui->title->setFont(logoFont);
    ui->title->setText(QString::fromStdString(title));
    setupTable();
}

void SharedMethodPageWidget::on_findRootBtn_clicked()
{
    ui->tableWidget->setRowCount(0);

    double a = ui->aBox->value();
    double epsilon = ui->epsilonBox->value();
    double maxSteps = ui->maxStepsBox->value() - 1;
    double initialGuess; /* = ui->guessBox->value();*/

    std::vector<ModelResult*> results = getResults(a, epsilon, initialGuess, maxSteps);
    populateTable(results);
}

void SharedMethodPageWidget::populateTable(std::vector<ModelResult*> results){
    for (int i = 0; i < results.size(); ++i) {
        ModelResult* result = results[i];

        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0,
                                 new QTableWidgetItem(QString::number(result->root)));
        ui->tableWidget->setItem(
            i, 1, new QTableWidgetItem(QString::number(result->errorFunction)));
        ui->tableWidget->setItem(
            i, 2, new QTableWidgetItem(QString::number(result->errorInterval)));

    }
}

void SharedMethodPageWidget::setupTable(){
    ui->tableWidget->setColumnCount(3);
    QStringList horizontalHeaders = {"xₖ",   "|f(xₖ)|",   "|xₖ+₁ - xₖ|"};
    ui->tableWidget->setHorizontalHeaderLabels(horizontalHeaders);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

SharedMethodPageWidget::~SharedMethodPageWidget()
{
    delete ui;
}
