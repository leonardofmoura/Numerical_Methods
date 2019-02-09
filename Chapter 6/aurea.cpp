#include <iostream>
#include <iomanip>
#include <cmath>


/* Test function */
double func1(double x) {
    return 0.28*pow(x,2) + 0.5*x + 2;
}


double aurea_min(double f(double), double min, double max, double err) {
    double B = (sqrt(5)-1)/2;
    double A = B*B;

    double x3, x4;

    while (std::abs(max - min) > err) {
        x3 = min + A*(max-min);
        x4 = min + B*(max-min);

        if (f(x3) < f(x4)) {
            max = x4;
        }
        else {
            min = x3;
        }
    
    }

    if (f(max) < f(min)) {
        return max;
    }
    else {
        return max;
    }

}

double aurea_max(double f(double), double min, double max, double err) {
    double B = (sqrt(5)-1)/2;
    double A = B*B;

    double x3, x4;

    while (std::abs(max - min) > err) {
        x3 = min + A*(max-min);
        x4 = min + B*(max-min);

        if (f(x3) > f(x4)) {
            max = x4;
        }
        else {
            min = x3;
        }
    }

    
    if (f(max) > f(min)) {
        return max;
    }
    else {
        return min;
    }

}

int main() {
    double err = 0.0000000001;
    double min = -1;
    double max = 0;

    std::cout << "Max: " << aurea_max(func1,min,max,err) << std::endl;
    std::cout << "Min: " << aurea_min(func1,min,max,err) << std::endl;


    return 0;
}