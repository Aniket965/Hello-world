#include <iostream>
#include <cmath>

double basicFormula(double b, double h) {
    return b*h/2;
}

double heronsFormula(double a, double b, double c) {
    double s = (a + b + c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double trigonometry(double a, double b, double angle) {
    double theta = angle * M_PI / 180;
    return a*b*sin(theta)/2;
}

int main() {
    int selection;
    std::cout << "Triangle Area Calculator" << std::endl
              << "Which formula do you want to use?" << std::endl
              << "1] Basic Formula (given base and height)" << std::endl
              << "2] Heron's Formula (given all sides)" << std::endl
              << "3] With Trigonometry (given two adjacent sides and the angle between them)" << std::endl
              << "(Type 1 / 2 / 3 to select): ";
    std::cin >> selection;

    switch (selection) {
        case 1: {
            double base, height;
            std::cout << "Basic Formula:" << std::endl
                      << "Give me the base of the triangle: ";
            std::cin >> base;

            std::cout << "Give me the height of the triangle: ";
            std::cin >> height;

            std::cout << "The area of the triangle with a base of " << base
                      << " and a height of " << height << " is " << basicFormula(base, height);
            break;
        }

        case 2: {
            double a, b, c;
            std::cout << "Heron's Formula:" << std::endl
                      << "Give me all the sides (space separated): ";
            std::cin >> a >> b >> c;

            std::cout << "The area of the triangle with sides (" << a << ", " << b << ", " << c << ") is "
                      << heronsFormula(a, b, c);
            break;
        }

        case 3: {
            double a, b, angle;
            std::cout << "Using Trigonometry:" << std::endl
                      << "Give me the two adjacent sides (space separated): ";
            std::cin >> a >> b;

            std::cout << "Give me the angle between them (in degrees): ";
            std::cin >> angle;

            std::cout << "The area of the triangle with two adjacent sides (" << a << ", " << b
                      << ") and an angle of "
                      << angle << " degrees between them is " << trigonometry(a, b, angle);
            break;
        }

        default: {
            std::cout << "Invalid Choice!";
            break;
        }
    }
    std::cout << std::endl;

    return 0;
}
