#ifndef BENTOMARKWIDGET_H
#define BENTOMARKWIDGET_H

#include "../../controllers/ModelResult.h"
#include <QWidget>

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
  ModelResult *getNewtonResults(double a, double initialGuess, double epsilon,
                                int maxSteps);
  ModelResult *getModifiedNewtonResults(double a, double initialGuess,
                                        double epsilon, int maxSteps);
  ModelResult *getSecantResults(double a, double initialGuess, double epsilon,
                                int maxSteps);

  void setupTable();
  void populateTable(ModelResult *newtonResults,
                     ModelResult *modifiedNewtonResults,
                     ModelResult *secantResults);
};

#endif // BENTOMARKWIDGET_H
