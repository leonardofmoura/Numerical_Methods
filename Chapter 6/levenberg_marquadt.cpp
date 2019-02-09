#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

double func1(double x, double y) {
    return pow((x + 1),2) + pow((y - 4),2);
}

// ===================================================
/* H^-1 * nabla = [x+1,y-4] */
double inverted_hessian_nablax1(double x, double y) {
    return x + 1;
}

double inverted_hessian_nablay1(double x, double y) {
    return y - 4;
}

// ===================================================

/* nabla = [2*x+2,2*y-8] */
double nablax1(double x, double y) {
    return 2*x + 2;
}

double nablay1(double x, double y) {
    return 2*y - 8;
}
//====================================================

/* inverted_hessian_nabla and nabla are vectors of function pointers that correspond to those matrices (column vectors) */
std::vector<double> lm(double f(double,double), double x0, double y0, double h, double err, std::vector<double (*)(double,double)> inverted_hessian_nabla, std::vector<double (*)(double,double)>  nabla) {
    std::vector<double> res;

    double xn = x0 +1;
    double yn = y0 +1;
    double hlmx, hlmy;
    unsigned int i = 0;
    

    while (std::abs(xn - x0) > err || std::abs(yn - y0) > err) {
        i++;
        x0 = xn;
        y0 = yn;

        hlmx = inverted_hessian_nabla[0](x0,y0) - h*nabla[0](x0,y0);
        hlmy = inverted_hessian_nabla[1](x0,y0) - h*nabla[1](x0,y0);

        xn = x0 - hlmx;
        yn = y0 - hlmy;

        if (f(xn,yn) <= f(x0,y0)) {
            h /= 2;
        }
        else {
            h *= 2;
        }

        std::cout << "x[" << i << "]:" << xn;
        std::cout << "    y[" << i << "]:" << yn << std::endl;

        if (i == 500) { //set a maximum number of iterations
            break;
        } 
    }


    res.push_back(xn);
    res.push_back(yn);

    return res;
}


int main() {
    double x0 = 0;
    double y0 = 0;
    double err = 0.000000000001;
    double h = 0.1;

    /* Create the inverted_hessian_nabla matrix */
    std::vector<double (*)(double,double)> inverted_hessian_nabla; 
    inverted_hessian_nabla.push_back(inverted_hessian_nablax1);
    inverted_hessian_nabla.push_back(inverted_hessian_nablay1);

    /* Create the nabla matrix */
    std::vector<double (*)(double,double)> nabla;
    nabla.push_back(nablax1);
    nabla.push_back(nablay1);


    std::vector<double> res = lm(func1,x0,y0,h,err,inverted_hessian_nabla,nabla);

    /* Print the result */
    for (int i = 0; i < res.size(); i++) {
        std::cout << "res[" << i << "]:" << res[i] << std::endl;
    }

    return 0;
}



