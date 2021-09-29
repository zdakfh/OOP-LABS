#include <iostream>
#include "D:\LABA2.2\StaticLib2\StaticLib2\relclass.h"
#include "dialog.h"
using namespace Prog2;
int main() {
    double A = 0;
    do {
        std::cout << "enter  coeficient a > 0" << std::endl;
        std::cout << std::endl;
        if (!get_num(A))
            std::cout << "find end of file" << std::endl;
            return 3;
    } while (A <= 0);
    double r = 0;
    do {
        std::cout << "enter radius R > 0" << std::endl;
        std::cout << std::endl;
        if (!get_num(r))
            std::cout << "find end of file" << std::endl;
            return 3;
    } while (r <= 0);
    Line p(A, r);
    int k = dialog(p);
    if (k == 3) {
        std::cout << "find end of file" << std::endl;
        return 3;
    }
    return 0;
}