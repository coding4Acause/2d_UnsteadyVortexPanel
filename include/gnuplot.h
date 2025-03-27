#ifndef GNUPLOT_H
#define GNUPLOT_H

#include <vector>
#include <Eigen/Eigen>
#include <cstdio>  // For FILE*

using namespace Eigen;
using namespace std;

/**
 * @file gnuplot.h
 * @brief Header file for Gnuplot visualization functions.
 *
 * This file contains the declaration of functions used for real time plotting
 * of wake vortices and airfoil shape using Gnuplot.
 */

/**
 * @brief Plots the wake vortices and airfoil shape in an in-situ simulation.
 *
 * This function takes the wake vortex locations and airfoil coordinates and
 * updates the Gnuplot window dynamically to visualize the wake evolution.
 *
 * @param gnuplotPipe Pointer to the Gnuplot pipe.
 * @param gamma_wake_x_location X-coordinates of previously shed wake vortices.
 * @param gamma_wake_y_location Y-coordinates of previously shed wake vortices.
 * @param wake_x1 X-coordinate of the starting point of recent shed wake panel.
 * @param wake_y1 Y-coordinate of the starting point of recent shed wake panel.
 * @param wake_x2 X-coordinate of the end point of recent shed wake panel.
 * @param wake_y2 Y-coordinate of the end point of recent shed wake panel.
 * @param x_pp X-coordinates of the airfoil surface.
 * @param y_pp Y-coordinates of the airfoil surface.
 */
void plot_wake(FILE *gnuplotPipe, const vector<double> &gamma_wake_x_location,const vector<double> &gamma_wake_y_location, double wake_x1,double wake_y1, double wake_x2, double wake_y2,const VectorXd &x_pp, const VectorXd &y_pp);

#endif // GNUPLOT_H
