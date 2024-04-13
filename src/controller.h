#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

namespace MyNamespace {

/**
 * @brief The Controller class. MVC-pattern part, used to connect View
 * (MainWindow & PlotWindow classes) with Model.
 */
class Controller {
 private:
  /**
   * @brief model - pointer to Model class object.
   */
  Model *model;

 public:
  /**
   * @brief Controller - basic constructor.
   */
  Controller();

  /**
   * @brief calculateValue - Controller class' method used to send string with
   * expression and X-value to Model, calls Model's methods of processing and
   * calculation.
   * @param expression - std::string type value. Contains expression to be
   * processed by Model.
   * @param x - double type value. Contains value of X-var.
   */
  void calculateValue(std::string expression, double x = 0);

  /**
   * @brief getValue - Controller class' method used to return result of
   * calculation from Model.
   * @return double type value. Result of calculation.
   */
  double getValue();

  /**
   * @brief calculateGraph - Controller class' method used to send string with
   * expression and X-values to Model, calls Model's methods of processing and
   * calculation to prepare data for plotting function graph.
   * @param expression - std::string type value. Contains expression to be
   * processed by Model.
   * @param xmin - double type value. Contains lower limit of the values
   * interval of X-var.
   * @param xmax - double type value. Contains higher limit of the values
   * interval of X-var.
   */
  void calculateGraph(std::string expression, double xmin = -100,
                      double xmax = 100);

  /**
   * @brief getGraphData - Controller class' method used to return calculated
   * data from Model to function graph plotting.
   * @return std::pair<QVector<double>, QVector<double>> type. Result of
   * calculation.
   */
  Model::graph_type getGraphData();

  ~Controller();
};

}  // namespace MyNamespace

#endif  // CONTROLLER_H
