#include <iostream>
#include <cmath>


//test function 1 
double f1(double x, double y) {     //in the form x = f1
    return sqrt((x*y + 5*x - 1)/2); 
}

//test function 2
double f2(double x, double y) {     //in the form y = f2
    return sqrt(x + 3*log(x));
}

//method implementation
void pic_pea(double guessX, double guessY, int nmax) {
    double OldGuessX, OldGuessY;

    for (int i = 0; i < nmax; i++) {
        OldGuessX = guessX;
        OldGuessY = guessY;

        guessX = f1(guessX,guessY);
        guessY = f2(guessX,guessY);

        std::cout << "x[" << i << "]:" << guessX << "     y[" << i << "]:" << guessY << std::endl;

        if (std::abs(OldGuessX - guessX) < pow(10,-5) && std::abs(OldGuessY - guessY) < pow(10,-5)) {
            break;
        }
    }
}

int main() {
    double guessX = 4;
    double guessY = 4;
    double nmax = 200;

    pic_pea(guessX,guessY,nmax);

    return 0;
}