#include <iostream>
#include <cmath>


//       **TEST FUNCTIONS**

double f1(double x, double y) {
    return 2*pow(x,2) - x*y - 5*x + 1;
}

double f2(double x, double y) {
    return x + 3*log(x) - pow(y,2);
}

//partial derivative of f1 in respect to x
double df1x(double x, double y) {
    return 4*x - y - 5;
}

//partial derivative of f1 in respect to y
double df1y(double x, double y) {
    return -x;
}

//partial derivative of f2 in respect to x
double df2x(double x, double y) {
    return 1 + 3/x;
}

//partial derivative of f2 in respect to y
double df2y(double x, double y) {
    return -2*y;
}


/*===================================  NEWTON ============================================*/
void newton_iter(double guess_x,double guess_y,int nmax) {  //with a max error of 10^-5
    double old_guess_x,old_guess_y;


    for (int i = 0; i < nmax; i++) {
        old_guess_x = guess_x;
        old_guess_y = guess_y;

        guess_x = guess_x - (f1(guess_x,guess_y)*df2y(guess_x,guess_y) - f2(guess_x,guess_y)*df1y(guess_x,guess_y)) 
            / (df1x(guess_x,guess_y)*df2y(guess_x,guess_y) - df2x(guess_x,guess_y)*df1y(guess_x,guess_y) );

        guess_y = guess_y - (f2(guess_x,guess_y)*df1x(guess_x,guess_y) - f1(guess_x,guess_y)*df2x(guess_x,guess_y)) /
            (df1x(guess_x,guess_y)*df2y(guess_x,guess_y) - df2x(guess_x,guess_y)*df1y(guess_x,guess_y));

        std::cout << "x[" << i << "]:" << guess_x << "    y[" << i << "]:" << guess_y << std::endl;

        if (std::abs(old_guess_x - guess_x) < pow(10,-5) && std::abs(old_guess_y - guess_y) < pow(10,-5)) { 
            break;
        } 
    }
}
/*=========================================================================================*/

int main() {
    double guess_x = 4;
    double guess_y = 4;
    double nmax = 20;

    newton_iter(guess_x,guess_y,nmax);

    return 0;
}
