//
// Created by Даниил on 27.09.2021.
//

#include <iostream>
#include <strstream>
#include "relclass.h"
#include <cmath>
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
namespace Prog2 {


    const char* error[]{
            "radius must be bigger than 0",
            "coefficient must be bigger than 0",
    };


    Line::Line(double A, double r) {
        if (A <= 0) {
            throw std::logic_error(error[1]);
        }
        if (r <= 0) {
            throw std::logic_error(error[0]);
        }
        a = A;
        R = r;
    }


    Line& Line::set_R(double valueR)
    {
        if (valueR <= 0)
            throw std::logic_error(error[0]);
        R = valueR;
        return *this;
    }


    Line& Line::set_a(double valuea)
    {
        if (valuea <= 0)
            throw std::logic_error(error[1]);
        a = valuea;
        return *this;
    }


    double Line::find_lenght(double x1, double x2, double r) {
        if (x1 >= x2) {
            return (r * (sinh(x1 / r) - sinh(x2 / r)));
        }
        else {
            return (r * (sinh(x2 / r) - sinh(x1 / r)));
        }
    }


    double Line::find_Radius(double x1, double A) {
        return A * cosh(x1 / A) * cosh(x1 / A);
    }


    double* Line::find_centre(double x1, double A) {
        double* coor = 0;
        try {
            coor = new double[2];
        }
        catch (const std::bad_alloc& ba)
        {
            std::cout << ba.what() << std::endl;
            delete[] coor;
            return nullptr;
        }
        coor[0] = (A * (sinh(x1 / A) * cosh(x1 / A) + log(cosh(x1 / A) - sinh(x1 / A))));
        coor[1] = 2 * A * cosh(x1 / A);
        return coor;
    }


    double Line::find_square(double x1, double x2, double A) {
        return abs(A * A * (sinh(x2 / A) - sinh(x1 / A)));
    }
}
