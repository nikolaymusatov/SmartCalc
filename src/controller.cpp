#include "controller.h"

using namespace MyNamespace;

Controller::Controller() : model(new Model()) {}

void Controller::calculateValue(std::string expression, double x) {
  model->calculateValue(expression, x);
}

double Controller::getValue() { return model->getResult(); }

void Controller::calculateGraph(std::string expression, double xmin,
                                double xmax) {
  model->calculateGraph(expression, xmin, xmax);
}

Model::graph_type Controller::getGraphData() { return model->getGraphData(); }

Controller::~Controller() { delete model; }
