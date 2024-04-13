#include <QApplication>

#include "mainwindow.h"

using namespace MyNamespace;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow calc;
  calc.show();
  return a.exec();
}
