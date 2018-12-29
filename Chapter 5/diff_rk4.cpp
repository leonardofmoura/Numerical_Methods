#include <iostream>
#include <iomanip>
#include <cmath>

double func1(double x, double y) {
    return x*x + y*y;
}

double diff_rk4_given_h(double f(double,double), double guessX, double guessY, double min, double max, double h) {
    double oldX, oldY;
    double dy1, dy2, dy3, dy4;
    int i = 0;

    while(guessX < max) {
        i++;

        oldX = guessX;
        oldY = guessY;

        dy1 = h*f(oldX,oldY);
        dy2 = h*f(oldX + h/2, oldY + dy1/2);
        dy3 = h*f(oldX+h/2, oldY+dy2/2);
        dy4 = h*f(oldX + h, oldY + dy3);

        guessX = oldX + h;
        guessY = oldY + dy1/6 + dy2/3 + dy3/3 + dy4/6;

        std::cout << "X[" << i << "] = " << guessX << "    Y[" << i << "] = " << guessY << std::endl;
    }

    std::cout << "\nX = " << guessX << "    Y = " << guessY << std::endl;

    return guessY;
}


void qc(double s, double sl, double sll) {
    double q = (sl-s)/(sll-sl);

    std::cout << "\nQC = " << q << std::endl;
}

void error(double sl, double sll) {
    double e = (sll-sl)/15;

    std::cout << "E = " << e << std::endl;
}


int main() {
    double guessX = 0;
    double guessY = 0;
    double min = 0;
    double max = 1.3999999999999;
    double h = 0.1/8;

    double s = diff_rk4_given_h(func1,guessX,guessY,min,max,h);
    double sl = diff_rk4_given_h(func1,guessX,guessY,min,max,h/2);
    double sll = diff_rk4_given_h(func1,guessX,guessY,min,max,h/4);

    qc(s,sl,sll);

    error(sl,sll);

    return 0;
}