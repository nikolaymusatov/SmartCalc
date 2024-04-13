#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QDialog>

#include "controller.h"

namespace Ui {
class PlotWindow;
}

namespace MyNamespace {

/**
 * @brief The PlotWindow class - View part of MVC-pattern. Used to set GUI for
 * function graph plotting.
 */
class PlotWindow : public QDialog {
  Q_OBJECT

 public:
  using graph_type = std::pair<QVector<double>, QVector<double>>;

  /**
   * @brief PlotWindow - basic constructor. Creates PlotWindow class object.
   * @param controller - pointer to MainWindow controller for communication with
   * Model
   * @param expression - user input expression from MainWindow.
   * @param parent - QWidget type.
   */
  explicit PlotWindow(Controller *controller, QString expression,
                      QWidget *parent = nullptr);
  ~PlotWindow();

 private slots:
  /**
   * @brief calcButton_clicked - slot for processing pressing Calculate-key.
   * Sends X-value to Model via Controller and recieves result value.
   */
  void calcButton_clicked();

  /**
   * @brief replotButton_clicked - slot for processing pressing Replot-key.
   * Collects data from Xmin, Xmax, Ymin, Ymax input fields and sends it to
   * Model via Controller to calculate new data for plotting.
   */
  void replotButton_clicked();

  /**
   * @brief xyChanged - slot for enabling and disabling Replot-key. Checks data
   * from Xmin, Xmax, Ymin, Ymax input fields and make the button enable for
   * user if all data is correct.
   */
  void xyChanged();

  /**
   * @brief valueInput - slot for enabling and disabling Calculate-key. Checks
   * data from X-input field and make the button enable for user if data is
   * correct.
   * @param a - const QString& type value. Containes users data from X-input
   * field.
   */
  void valueInput(const QString &a);

  /**
   * @brief keyPressEvent - slot for processing pressing Enter-key. Calls
   * calcButton_clicked() and replotButton_clicked() if Calculate-button and
   * Replot-button are avaliable.
   * @param event - Enter-key pressing by user.
   */
  void keyPressEvent(QKeyEvent *event);

 private:
  /**
   * @brief function - QString type value. Contains user input expression from
   * MainWindow.
   */
  QString function;

  /**
   * @brief ui - form of PlotWindow GUI.
   */
  Ui::PlotWindow *ui;

  /**
   * @brief controller - pointer to Controller class object.
   */
  Controller *controller;

  /**
   * @brief plot - method used to create function graph using graphData
   * calculated by Model.
   * @param xmin - double type value. Contains lower limit value for X-axis.
   * @param xmax - double type value. Contains higher limit value for X-axis.
   */
  void plot(double xmin = -100, double xmax = 100);
};

}  // namespace MyNamespace

#endif  // PLOTWINDOW_H
