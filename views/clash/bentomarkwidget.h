#ifndef BENTOMARKWIDGET_H
#define BENTOMARKWIDGET_H

#include "../../controllers/ModelResult.h"
#include "vector"
#include <QWidget>

using namespace std;
namespace Ui {
class BentomarkWidget;
}

class BentomarkWidget : public QWidget {
  Q_OBJECT

public:
  explicit BentomarkWidget(int pos, double initialGuess, double epsilon,
                           int maxSteps, QWidget *parent = nullptr);
  ~BentomarkWidget();

public slots:
  void onFindRootClicked();

private:
  Ui::BentomarkWidget *ui;
  vector<ModelResult *> getNewtonResults(double a, double initialGuess,
                                         double epsilon, int maxSteps);
  vector<ModelResult *> getModifiedNewtonResults(double a, double initialGuess,
                                                 double epsilon, int maxSteps);
  vector<ModelResult *> getSecantResults(double a, double initialGuess,
                                         double epsilon, int maxSteps);

  void setupTable();
  void populateTable(vector<ModelResult *> newtonResults,
                     vector<ModelResult *> modifiedNewtonResults,
                     vector<ModelResult *> secantResults);
};

#endif // BENTOMARKWIDGET_H
