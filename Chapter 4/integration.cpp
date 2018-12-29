  #include <iostream>
#include <cmath>

double func1(double x) {
    return (sin(x)/pow(x,2));
}


double trapezoid_given_n(double f(double), double a, double b, int n) {
    double h = (b-a)/n;
    double h1 = h/2;
    double sum = 0;

    sum += f(a);

    for (int i = 1; i <= n-1 ; i++) {
        sum += 2*f(a+i*h);
    }

    sum += f(b);
    
    return sum*h1;
}

double simpson_given_n(double f(double), double a, double b, int n) {
    double h = (b-a)/n;
    double h1 = h/3;
    double sum = 0;

    sum += f(a);

    for (int i = 1; i <= n-1; i++) {
        if ((i % 2) == 0) {
            sum += 2*f(a+i*h);
        }
        else {
            sum += 4*f(a+i*h);
        }
    }

    sum += f(b);

    return sum*h1;
}

double convergence_quotient_trapezoid_given_n(double f(double), double a, double b, int n) {
    double s = trapezoid_given_n(f, a,b,n);
    double sl = trapezoid_given_n(f, a, b, 2*n);
    double sll = trapezoid_given_n(f, a, b , 4*n);

    double Q = (sl-s)/(sll-sl);

    return Q; 
}

double convergence_quotient_simpson_given_n(double f(double), double a, double b, int n) {
    double s = simpson_given_n(f, a,b,n);
    double sl = simpson_given_n(f, a, b, 2*n);
    double sll = simpson_given_n(f, a, b , 4*n);

    double Q = (sl-s)/(sll-sl);

    return Q; 
}

double error_trapezoid(double f(double), double a, double b, int n) {
    double sl = trapezoid_given_n(f, a, b, 2*n);
    double sll = trapezoid_given_n(f, a, b , 4*n);

    return (sll - sl)/3;
}

double error_simpson(double f(double), double a, double b, int n) {
    double sl = simpson_given_n(f, a, b, 2*n);
    double sll = simpson_given_n(f, a, b , 4*n);

    return (sll-sl)/15;
}

int main() {
    double a = acos(-1)/2;
    double b = acos(-1);
    int n = 4;

    std::cout << "\nIntergral_t:" << trapezoid_given_n(func1, a,b,n) << std::endl;
    std::cout << "QC_t:" << convergence_quotient_trapezoid_given_n(func1,a,b,n) << std::endl;
    std::cout << "Error_t:" << error_trapezoid(func1,a,b,n) << std::endl;
    std::cout << "\nIntegral_s:" << simpson_given_n(func1,a,b,4*n) << std::endl;
    std::cout << "QC_s:" << convergence_quotient_simpson_given_n(func1,a,b,4*n) << std::endl;
    std::cout << "Error_s:" << error_simpson(func1,a,b,4*n) << std::endl << std::endl;

    return 0;
}