#include <iostream>
#include <limits>
#include "D:\LABA2.2\StaticLib2\StaticLib2\relclass.h"

using namespace Prog2;
template <class T>
int get_num(T& a) {
    const char* pr = "";
    do {
        std::cout << pr << std::endl;
        pr = "You are wrong  \\(-_-)/ repeat please!";
        std::cin >> a;
        if (std::cin.eof())
            return 0;
        if (!std::cin.good()) {
            std::cout << "Enter integer or double!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else 
            return 1;
        
    } while (true);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int dialog(Line& x) {

    int choise;
    do {
        std::cout << "Make your choice: --> \n" << std::endl;
        puts(" Enter 1 to find centre \n"
            "Enter 2 to find square\n"
            "Enter 3 to find radius \n"
            "Enter 4 to  find lenght\n"
            "Enter 5 to change R\n"
            "Enter 6 to change a \n"
            "Enter any Natural  to quit\n");
        get_num(choise); 
        if (choise == 1) {
            double l1;
            double* p;
            std::cout << " enter x" << std::endl;
            if (!get_num(l1))
                return 3;
            std::cout << std::endl;
            p = x.find_centre(l1, x.get_a());
            if (!p) {
                return 2;
            }
            std::cout << "x = " << *p << std::endl;
            p++;
            std::cout << "y = " << *p << std::endl;
            p--;
            delete[] p;
        }
        else if (choise == 2) {
            double l1;
            double l2;
            std::cout << " enter x1" << std::endl;
            if (!get_num(l1))
                return 3;
            std::cout << std::endl;
            std::cout << "enter x2" << std::endl;
            if (!get_num(l2))
                return 3;
            std::cout << x.find_square(l1, l2, x.get_a()) << std::endl;

        }
        else if (choise == 3) {
            double l1;
            std::cout << " enter x" << std::endl;
            if (!get_num(l1))
                return 3;
            std::cout << std::endl;
            std::cout << x.find_Radius(l1, x.get_a()) << std::endl;
        }
        else if (choise == 4) {
            double l1;
            double l2;
            std::cout << " enter x1" << std::endl;
            if (!get_num(l1))
                return 3;
            std::cout << std::endl;
            std::cout << "enter x2" << std::endl;
            if (!get_num(l2))
                return 3;
            std::cout << std::endl;
            std::cout << x.find_lenght(l1, l2, x.get_R()) << std::endl;

        }
        else if (choise == 5) {
            std::cout << " enter a" << std::endl;
            x.get_a();
            std::cout << std::endl;
        }
        else if (choise == 6) {
            std::cout << " enter a" << std::endl;
            x.get_R();
            std::cout << std::endl;
        }
        else {
            choise = -1;
            break;
        }
    } while (choise != -1);
}