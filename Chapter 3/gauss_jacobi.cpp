#include <iostream>
#include <cmath>
#include <vector>

typedef std::vector<std::vector<double>> matrix;


std::vector<double> gauss_jacobi(matrix mat, std::vector<double> guess, unsigned int nmax) {
    unsigned int n = 0;
    std::vector<double> res = guess;

    while (n < nmax) {
	for (int i = 0; i < mat.size(); i++) { //number of unknowns
		double sum = 0; 
		for (int j = 0; j < mat.size(); j++) {
			if (j == i) {
				continue;
			}

			sum += (-mat[i][j]*res[j]);
		}
	    guess[i] = (sum + mat[i][mat[i].size()-1])/mat[i][i];
		
	} 

	n++;	
	res = guess;
    }


    return res; 
}


void print_vec(std::vector<double> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << "[" << vec[i] << "]\n";
	}
	std::cout << std::endl;
}



int main() {
	matrix mat = { {5,2,3,-1},
		           {-3,9,1,2},
		    	   {2,-1,-7,3} };
	
	std::vector<double> guess = {0,0,0};
	unsigned int nmax = 10;

	print_vec(gauss_jacobi(mat,guess,nmax));

	return 0;
}


