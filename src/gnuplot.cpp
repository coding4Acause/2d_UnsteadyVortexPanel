#include "gnuplot.h"
#include <iostream>

using namespace Eigen;
using namespace std;

void plot_wake(FILE *gnuplotPipe, const vector<double> &gamma_wake_x_location, const vector<double> &gamma_wake_y_location, double wake_x1, double wake_y1, double wake_x2, double wake_y2, const VectorXd &x_pp, const VectorXd &y_pp)
{
    fprintf(gnuplotPipe, "set terminal x11\n");  // Ensure X11 is used
    fprintf(gnuplotPipe, "set size ratio -1\n"); // Equal axis scaling

    fprintf(gnuplotPipe, "plot '-' with points pt 7 ps 1.0 lc rgb 'red', '-' with lines lw 3 lc rgb 'blue'\n");

    // Plot wake vortices (Red points)
    fprintf(gnuplotPipe, "%lf %lf\n", wake_x1, wake_y1);
    fprintf(gnuplotPipe, "%lf %lf\n", wake_x2, wake_y2);
    for (size_t k = 0; k < gamma_wake_x_location.size(); k++)
    {
        fprintf(gnuplotPipe, "%lf %lf\n", gamma_wake_x_location[k], gamma_wake_y_location[k]);
    }
    fprintf(gnuplotPipe, "e\n"); // End of first dataset (wake vortices)

    // Plot airfoil (Blue line)
    for (int i = 0; i < x_pp.size(); i++)
    {
        fprintf(gnuplotPipe, "%lf %lf\n", x_pp(i), y_pp(i));
    }
    fprintf(gnuplotPipe, "e\n"); // End of second dataset (airfoil)
    fflush(gnuplotPipe);         // Update plot immediately
}
