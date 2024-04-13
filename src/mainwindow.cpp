#include "mainwindow.h"

#include "ui_mainwindow.h"

using namespace MyNamespace;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      controller(new Controller()) {
  ui->setupUi(this);
  ui->lineEdit->setPlaceholderText("Expression");
  connect(ui->pushButton_0, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(div_clicked()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(mult_clicked()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_op, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_cp, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this,
          SLOT(digits_and_funcs_clicked()));
  connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(AC_clicked()));
  connect(ui->pushButton_bs, SIGNAL(clicked()), this,
          SLOT(backspace_clicked()));
  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(equal_clicked()));
  connect(ui->pushButton_plot, SIGNAL(clicked()), this, SLOT(plot_clicked()));
}

MainWindow::~MainWindow() {
  delete ui;
  delete controller;
}

void MainWindow::digits_and_funcs_clicked() {
  QPushButton *button = (QPushButton *)sender();
  ui->lineEdit->setText(ui->lineEdit->text() + button->text());
}

void MainWindow::mult_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + " * ");
}

void MainWindow::div_clicked() {
  ui->lineEdit->setText(ui->lineEdit->text() + " / ");
}

void MainWindow::AC_clicked() { ui->lineEdit->setText(""); }

void MainWindow::backspace_clicked() { ui->lineEdit->backspace(); }

void MainWindow::equal_clicked() {
  QString expression = ui->lineEdit->text();
  if (expression.contains('x')) {
    QMessageBox::critical(
        this, "Warning",
        QString::fromStdString("Use \"plot\" to work with functions"));
  } else if (!expression.isEmpty()) {
    try {
      controller->calculateValue(expression.toStdString());
      ui->lineEdit->setText(QString::number(controller->getValue()));
    } catch (std::string e) {
      QMessageBox::critical(this, "Warning",
                            QString::fromStdString("Invalid data: " + e));
    }
  }
}

void MainWindow::plot_clicked() {
  QString expression = ui->lineEdit->text();
  if (!expression.isEmpty()) {
    try {
      controller->calculateGraph(expression.toStdString());
      plotwindow = new PlotWindow(controller, expression);
      plotwindow->setModal(true);
      plotwindow->show();
    } catch (std::string e) {
      QMessageBox::critical(this, "Warning",
                            QString::fromStdString("Invalid data: " + e));
    }
  }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Return) equal_clicked();
}
