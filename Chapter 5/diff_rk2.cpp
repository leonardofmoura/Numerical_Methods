#include <iostream>
#include <iomanip>
#include <cmath>


double func1(double x, double y) {
    return x*x+y*y;
}


double diff_rk2_given_h(double f(double,double), double guessX, double guessY, double min, double max, double h) {
    double oldX, oldY;
    int i = 0;

    while(guessX < max) {
        i++;

        oldX = guessX;
        oldY = guessY;

        guessX = oldX + h;
        guessY = oldY + h*f(oldX + h/2, oldY + h/2*f(oldX,oldY));

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
    double e = (sll-sl)/3;

    std::cout << "E = " << e << std::endl;
}


int main() {
    double guessX = 0;
    double guessY = 0;
    double min = 0;
    double max = 1.3999999999999;
    double h = 0.1;

    double s = diff_rk2_given_h(func1,guessX,guessY,min,max,h);
    double sl = diff_rk2_given_h(func1,guessX,guessY,min,max,h/2);
    double sll = diff_rk2_given_h(func1,guessX,guessY,min,max,h/4);

    qc(s,sl,sll);

    error(sl,sll);

    return 0;
}
