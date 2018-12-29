#include <iostream>
#include <cmath>
#include <iomanip>


double func1(double x,double y) {
    return(pow(x,2)+pow(y,2));
}

//very straight forward: just uses the formula
double diff_euler_given_h(double f(double,double), double guessX, double guessY,double a, double b, double h) {
    int i = 0;

    while(guessX<b) {
        i++;

        guessY = guessY + h*f(guessX,guessY);
        guessX = guessX + h;

        
        std::cout << "X[" << i << "]:" << guessX << "  Y[" << i << "]:" << guessY;
        std::cout << "  -->  y' = " << f(guessX,guessY) << std::endl;
    }

    std::cout << "\nX:" << guessX << "   Y:" << guessY << "  -->  " << func1(guessX,guessY) << std::endl;
    return guessY;
}

int main() {
    double guessX = 0;
    double guessY = 0;
    double a = 0;
    double b = 1.39999;
    double h = 0.1;

    double S = diff_euler_given_h(func1, guessX, guessY,a,b,h);
    double Sl = diff_euler_given_h(func1, guessX, guessY,a,b,h/2);
    double Sll = diff_euler_given_h(func1, guessX, guessY,a,b,h/4);

    double Qc = (Sl - S)/(Sll-Sl);
    std::cout << "QC=" << Qc << std::endl;

    double err = Sll - Sl;
    std::cout << "err=" << err << std::endl;

}
