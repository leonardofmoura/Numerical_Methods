#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

double func1(double x, double y) {
    return sin(y) + pow(y,2)/4 + cos(x) + pow(x,2)/4 - 1;
}

double df1x(double x) {
    return x/2 - sin(x);
}

double df1y(double y) {
    return cos(y) + y/2;
}


std::vector<double> gradiente_min(double f(double,double), double dfx(double), double dfy(double), double x0, double y0, double err) {
    double h = 1;

    double prev_x, prev_y;

    while (std::abs(x0 - prev_x) > err || std::abs(y0 - prev_y) > err) {
        prev_x = x0;
        prev_y = y0;

        x0 = prev_x - h*dfx(prev_x);
        y0 = prev_y - h*dfy(prev_y);

        if (f(x0,y0) < f(prev_x,prev_y)) {
            h *= 2;
        }
        else {
            x0 = prev_x;
            y0 = prev_y;
            h /= 2;
        }
    } 


    std::vector<double> res;
    res.push_back(x0);
    res.push_back(y0);

    return res;
}

int main() {
    double x0 = 0.1;
    double y0 = 0.1;
    double err = 0.00001;

    std::vector<double> res = gradiente_min(func1,df1x,df1y,x0,y0,err);

    std::cout << "X = " << res[0] << std::endl;
    std::cout << "Y = " << res[1] << std::endl;

    return 0;
}

