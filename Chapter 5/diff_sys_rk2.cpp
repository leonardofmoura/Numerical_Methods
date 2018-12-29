#include <iostream>
#include <cmath>
#include <iomanip>

double func1(double x, double y, double z) {
    return (z*y + x); 
}

double func2(double x, double y, double z) {
    return (z*x + y);
}

double rk2_sys_given_h(double f(double,double,double), double g(double,double,double), double guessX, double guessY, double guessZ, double min, double max, double h) {
    double oldX, oldY, oldZ;
    int i = 0;

    while(guessX < max) {
        i++;

        oldX = guessX;
        oldY = guessY;
        oldZ = guessZ;

        guessX = oldX + h;
        guessY = oldY + h*f(oldX+h/2,oldY+h/2*f(oldX,oldY,oldZ),oldZ+h/2*g(oldX,oldY,oldZ));
        guessZ = oldZ + h*g(oldX+h/2,oldY+h/2*f(oldX,oldY,oldZ),oldZ+h/2*g(oldX,oldY,oldZ));

        std::cout << "X[" << i << "] = " << guessX << "    Y[" << i << "] = " << guessY << "    Z[" << i  <<"] = " << guessZ << std::endl;
    }

    std::cout << "\nX: " << guessX << "    Y:" << guessY << "    Z:" << guessZ << " --> y'=" << f(guessX,guessY,guessZ) << std::endl << std::endl;
    return guessY;
}

int main() {
    double guessX = 0;
    double guessY = 1;
    double guessZ = 1;
    double min = 0;
    double max = 0.499999999999;
    double h= 0.1;

    double s = rk2_sys_given_h(func1,func2,guessX,guessY,guessZ,min,max,h/4);
    double sl = rk2_sys_given_h(func1,func2,guessX,guessY,guessZ,min,max,h/8);
    double sll = rk2_sys_given_h(func1,func2,guessX,guessY,guessZ,min,max,h/16);
   
    double qc = (sl-s)/(sll-sl);
    double err = (sl-s)/3;
 
    std::cout << "QC=" << qc << std::endl;

    std::cout << "err=" << err << std::endl;
}




