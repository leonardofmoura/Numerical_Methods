#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

//test function
double func1(double x, double y)  {
    return(exp(y-x));
}

//simpson method modified for two variable functions
double simpson_given_h(std::vector<double> values, double h) {
    double sum = 0;

    sum += values[0];

    for (int i = 1; i < values.size() - 1; i++) {
        if ((i % 2) == 0) {
            sum += 2*values[i];
        }
        else {
            sum += 4*values[i];
        }
    }

    sum += values[values.size()-1];

    return sum*(h/3);
}

//we use a simpson method in each row, then we use the simpson method again with the results of the rows
double cubatura_simpson_given_n(double f(double,double), double minX, double maxX, double minY, double maxY, int nX, int nY) {
    double hX = (maxX - minX)/nX;
    double hY = (maxY - minY)/nY;
    std::vector<double> temp_simpson;
    std::vector<double> simpson_results;
    double sum;

    for (int j = 0; j <= nY; j++) {
        temp_simpson.clear(); //clear the temporary vector
        for (int i = 0; i <= nX; i++) {
            temp_simpson.push_back(f(minX + i*hX, minY + j*hY));
            std::cout << std::right << std::setw(4) << "(" << minX + i*hX << "," << minY + j*hY << ")"; //prin the grid
        }
        std::cout << std::endl;
        simpson_results.push_back(simpson_given_h(temp_simpson,hX));
    }

    sum = simpson_given_h(simpson_results,hY);

    return sum;
}


int main() {
    double minX = 0;
    double maxX = 0.5;
    double minY = 0;
    double maxY = 0.5;
    double hX = 0.25;
    double hY = 0.25;
    int nX = (maxX - minX)/hX;
    int nY = (maxY - minY)/hY;


    std:: cout << cubatura_simpson_given_n(func1,minX,maxX,minY,maxY,nX,nY) << std::endl;
}
