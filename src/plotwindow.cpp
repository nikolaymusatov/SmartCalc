#include "plotwindow.h"

#include "ui_plotwindow.h"

using namespace MyNamespace;

PlotWindow::PlotWindow(Controller *controller, QString expression,
                       QWidget *parent)
    : QDialog(parent),
      function(expression),
      ui(new Ui::PlotWindow),
      controller(controller) {
  ui->setupUi(this);
  ui->xmin->setPlaceholderText("Xmin");
  ui->xmax->setPlaceholderText("Xmax");
  ui->ymin->setPlaceholderText("Ymin");
  ui->ymax->setPlaceholderText("Ymax");
  ui->input->setPlaceholderText("Enter X value");
  ui->output->setPlaceholderText("F(X) value");
  ui->replotButton->setDisabled(true);
  ui->calcButton->setDisabled(true);
  connect(ui->calcButton, SIGNAL(clicked()), this, SLOT(calcButton_clicked()));
  connect(ui->replotButton, SIGNAL(clicked()), this,
          SLOT(replotButton_clicked()));
  connect(ui->xmin, SIGNAL(textChanged(QString)), this, SLOT(xyChanged()));
  connect(ui->xmax, SIGNAL(textChanged(QString)), this, SLOT(xyChanged()));
  connect(ui->ymin, SIGNAL(textChanged(QString)), this, SLOT(xyChanged()));
  connect(ui->ymax, SIGNAL(textChanged(QString)), this, SLOT(xyChanged()));
  connect(ui->input, SIGNAL(textChanged(QString)), this,
          SLOT(valueInput(QString)));
  plot();
}

PlotWindow::~PlotWindow() { delete ui; }

void PlotWindow::plot(double xmin, double xmax) {
  graph_type graphData = controller->getGraphData();
  auto yRange =
      std::minmax_element(graphData.second.begin(), graphData.second.end());
  ui->widget->xAxis->setRange(xmin, xmax);
  if (*yRange.first == *yRange.second)
    ui->widget->yAxis->setRange(*yRange.first - 2, *yRange.second + 2);
  else
    ui->widget->yAxis->setRange(*yRange.first, *yRange.second);
  ui->widget->setBackground(QColor(50, 50, 50));
  ui->widget->xAxis->setTickLabelColor(Qt::white);
  ui->widget->xAxis->setBasePen(QPen(Qt::white));
  ui->widget->xAxis->setTickPen(QPen(Qt::white));
  ui->widget->xAxis->setSubTickPen(QPen(Qt::white));
  ui->widget->yAxis->setTickLabelColor(Qt::white);
  ui->widget->yAxis->setBasePen(QPen(Qt::white));
  ui->widget->yAxis->setTickPen(QPen(Qt::white));
  ui->widget->yAxis->setSubTickPen(QPen(Qt::white));
  ui->widget->addGraph();
  ui->widget->graph(0)->setData(graphData.first, graphData.second);
  ui->widget->graph(0)->setPen(QPen(QColor(255, 151, 57), 2));
  ui->widget->replot();
}

void PlotWindow::calcButton_clicked() {
  double x = ui->input->text().toDouble();
  controller->calculateValue(function.toStdString(), x);
  ui->output->setText(QString::number(controller->getValue()));
}

void PlotWindow::replotButton_clicked() {
  if (!ui->xmin->text().isEmpty()) {
    double xmin = ui->xmin->text().toDouble();
    double xmax = ui->xmax->text().toDouble();
    controller->calculateGraph(function.toStdString(), xmin, xmax);
    plot(xmin, xmax);
  }
  if (!ui->ymin->text().isEmpty()) {
    double ymin = ui->ymin->text().toDouble();
    double ymax = ui->ymax->text().toDouble();
    ui->widget->yAxis->setRange(ymin, ymax);
    ui->widget->replot();
  }
}

void PlotWindow::xyChanged() {
  QString xmin = ui->xmin->text(), xmax = ui->xmax->text(),
          ymin = ui->ymin->text(), ymax = ui->ymax->text();
  std::array<bool, 4> checkMatrix[3] = {
      {1, 1, 0, 0}, {0, 0, 1, 1}, {1, 1, 1, 1}};
  std::array<bool, 4> isEmptyMatrix = {!xmin.isEmpty(), !xmax.isEmpty(),
                                       !ymin.isEmpty(), !ymax.isEmpty()};
  for (int i = 0; i < 3; i++) {
    if (checkMatrix[i] == isEmptyMatrix) {
      if (i == 0 && xmin.toDouble() < xmax.toDouble())
        ui->replotButton->setDisabled(false);
      else if (i == 1 && ymin.toDouble() < ymax.toDouble())
        ui->replotButton->setDisabled(false);
      else if (i == 2 && xmin.toDouble() < xmax.toDouble() &&
               ymin.toDouble() < ymax.toDouble())
        ui->replotButton->setDisabled(false);
      else
        ui->replotButton->setDisabled(true);
      break;
    } else {
      ui->replotButton->setDisabled(true);
    }
  }
}

void PlotWindow::valueInput(const QString &a) {
  const std::regex regex_num("-?\\d+([.]\\d+)?(e([-+])?\\d+)?");
  ui->calcButton->setDisabled(a.isEmpty() ||
                              !std::regex_match(a.toStdString(), regex_num));
  if (a.isEmpty()) ui->output->clear();
}

void PlotWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Return) {
    if (ui->calcButton->isEnabled()) calcButton_clicked();
    if (ui->replotButton->isEnabled()) replotButton_clicked();
  }
}
