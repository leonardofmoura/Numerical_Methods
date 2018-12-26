#include <iostream>
#include <cmath>
#include <iomanip>

//because at the time i wanted to practice c++ exceptions
class no_solution_found {};
class input_error {};

// test function 1
double func1(double x) { //x^4 - x^2 = 0
    return (pow(x,4) - pow(x,2));
}

//test function 2
double func2(double x) {
    return (pow(x,4) + 2 * pow(x,3) - x - 1 );
}

//method implementation
double bissec(double f(double), double min, double max, double max_error, int nmax) {
    double mid_value;

    if (f(min) * f(max) > 0) {  //this means f(min) and f(max) are both negative or positive
        throw input_error();    //which means the method does not work
    }

    for (int i = 0; i < nmax; i++) {
        mid_value = (max + min)/2; 

        std::cout << "min:" << min << "     max:" << max << "     f(c):" << f(mid_value) << std::endl;

        if (f(mid_value) == 0 || ((max - min) < max_error)) { 
            return mid_value;
        }
        else {
            if (f(min)  * f(mid_value) > 0){    //sign(f(min)) = sign(f(mid_value))
                min = mid_value;                //if they have the same sign mid should be the new min 
            }
            else {                              //sign(f(max)) = sign(f(mid_value))
                max = mid_value;                //if they have the same sign mid should be the new max 
            }
        }

    }
    
    throw no_solution_found();
}


int main() {
    std::cout << "BISSECTION METHOD" << std::endl << std::endl;
    double min, max, max_error, result;
    int nmax;

    std::cout << "Min:"; std::cin >> min;
    std::cout << "Max:"; std::cin >> max;
    std::cout << "Max Error:"; std::cin >> max_error;
    std::cout << "Max Iterations:"; std::cin >> nmax;
    std::cout << std::endl << std::endl;

    try {
        result = bissec(func2, min, max, max_error, nmax);
    }
    catch (no_solution_found) {
        std::cout << "No solution found with max error given!" << std::endl;
        return 1;
    }
    catch (input_error) {
        std::cout << "f(a) * f(b) > 0" << std::endl;
        return 1;
    }

    std::cout << "Solution: " << result << std::endl;

    return 0;
}