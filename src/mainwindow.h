#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include <QMessageBox>

#include "controller.h"
#include "plotwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace MyNamespace {

/**
 * @brief The MainWindow class - View part of MVC-pattern. Used to set GUI.
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  /**
   * @brief MainWindow basic constructor.
   * @param parent - QWidget type.
   */
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  /**
   * @brief digits_and_funcs_clicked - slot for processing pressing keys of
   * operators, functions and numbers.
   */
  void digits_and_funcs_clicked();

  /**
   * @brief mult_clicked - slot for processing pressing multiplication-key.
   */
  void mult_clicked();

  /**
   * @brief div_clicked - slot for processing pressing division-key.
   */
  void div_clicked();

  /**
   * @brief AC_clicked - slot for processing pressing AC-key. Clears input
   * field.
   */
  void AC_clicked();

  /**
   * @brief backspace_clicked - slot for processing pressing backspace-key.
   * Deletes last charecter in input field.
   */
  void backspace_clicked();

  /**
   * @brief plot_clicked - slot for processing pressing plot-key. Creates
   * PlotWindow class example and GUI for function graph plotting.
   */
  void plot_clicked();

  /**
   * @brief equal_clicked - slot for processing pressing equal-key. Calls the
   * appropriate controller methods to pass a string with an expression from the
   * input field for processing by the Model.
   */
  void equal_clicked();

  /**
   * @brief keyPressEvent - slot for processing pressing Enter-key. Calls
   * equal_clicked().
   * @param event - Enter-key pressing by user.
   */
  void keyPressEvent(QKeyEvent *event);

 private:
  /**
   * @brief ui - form of MainWindow GUI.
   */
  Ui::MainWindow *ui;

  /**
   * @brief controller - pointer to Controller class object.
   */
  Controller *controller;

  /**
   * @brief plotwindow - pointer to PlotWindow class object.
   */
  PlotWindow *plotwindow;
};

}  // namespace MyNamespace

#endif  // MAINWINDOW_H
