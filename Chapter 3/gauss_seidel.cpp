#include<iostream>
#include<cmath>
#include<vector>


typedef std::vector<std::vector<double>> Matrix;


std::vector<double> gauss_seidel(Matrix mat, std::vector<double> guess, unsigned int nmax) {
	unsigned int n = 0;
	std::vector<double> res = guess;

	while (n < nmax) {
		for (size_t i = 0; i < mat.size(); i++) { //number of unknowns 
			double sum1 = 0;
			double sum2 = 0;

			for (size_t j = 0; j < i; j++) {
				sum1 += mat[i][j]*guess[j]; 
			}
			for (size_t j = i+1; j < mat.size(); j++) {
				sum2 += mat[i][j]*res[j];
			} 

			guess[i] = (-sum1 - sum2 + mat[i][mat[i].size()-1])/mat[i][i];
		}
		res = guess;
		n++;
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
	Matrix mat = {{5,2,3,-1},{-3,9,1,2},{2,-1,-7,3}};
	std::vector<double> guess = {0,0,0};
	unsigned int nmax = 10;

	print_vec(gauss_seidel(mat,guess,nmax));

	return 0;
}




