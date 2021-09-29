#ifndef MAIN_CPP_RELCLASS_H
#define MAIN_CPP_RELCLASS_H
#include <iostream>
#include <cmath>

namespace Prog2 {
    class Line {
    private:
        double a;
        double R; // вершина цепной линии
    public:
        Line(double A, double r);
        double get_a() {
            return a;
        }
        double get_R() {
            return R;
        }
        Line& set_a(double valuea);
        Line& set_R(double valueR);
        double find_lenght(double x1, double x2, double R);
        double find_Radius(double x1, double A);
        double* find_centre(double x1, double A);
        double find_square(double x1, double x2, double A);
    };
}
#endif //MAIN_CPP_RELCLASS_H

