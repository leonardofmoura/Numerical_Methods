#include <iostream>
#include <cmath>

//because at the time i wanted to practice c++ exceptions
class input_error {};
class no_solution_found {};

//test function
double func1(double x) {
    return pow(x,4) + 2 * pow(x,3) - x - 1;
}

//method implementation
double regula_falsi(double f(double), float min, float max, double max_error, int nmax) {
    if (f(min) * f(max) > 0) {  //this means f(min) and f(max) are both negative or positive
        throw input_error();    //which means the method does not work    
    }

    double possible_root;

    for (int i = 0; i < nmax; i++) {
        possible_root = (min*f(max) - max*f(min)) / (f(max) - f(min));

        std::cout << "min:" << min << "     max:" << max << "     f(c):" << f(possible_root) << std::endl;

        if ((max - min) < max_error || std::abs(f(possible_root)) < max_error) { //test the error
            return possible_root;
        }

        if ((f(min) * f(possible_root)) < 0) {  //test if they have same sign
            max = possible_root;                //possible_root is the new max
        } 
        else{
            min = possible_root;                //possible_root is the new min
        } 
    }

    throw no_solution_found();
}


int main() {
    std::cout << "REGULA FALSI METHOD" << std::endl << std::endl;
    double min, max, max_error, result;
    int nmax;

    std::cout << "Min:"; std::cin >> min;
    std::cout << "Max:"; std::cin >> max;
    std::cout << "Max Error:"; std::cin >> max_error;
    std::cout << "Max Iterations:"; std::cin >> nmax;
    std::cout << std::endl << std::endl;

    try {
        result = regula_falsi(func1, min, max, max_error, nmax);
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