#include <iostream>
#include <cmath>
#include <vector>

/*  This is my second implementation of the Gauss method:
    The first one failed compeletely so I decided to rewrite it all
    This one works tho  */ 

void print_matrix(std::vector<std::vector<double>>& matrix) {
    for (int i = 0; i < matrix.size() ; i++) {
        for (int j = 0; j < matrix[i].size(); j++ ) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}


//only works if the matrix does not have any zero in the main diagonal
std::vector<double> gauss_elim(std::vector<std::vector<double>>& matrix) { 
    std::vector<std::vector<double>> res_matrix;
    std::vector<double> res;

    //create the superior triangular matrix (i refers the current row being computed)
    for (int i = 0; i < matrix.size() - 1; i++) {
        double diag_elem = matrix[i][i];

        for (int j = 0; j < matrix[i].size(); j++) { //(j refers to the current line)
            matrix[i][j] /= diag_elem; //divide all the row by the diagonal element
        }

        //subtract all the lines bellow by that line
        for (int j = i + 1; j < matrix.size(); j++) { //j refers to the current line
            double multiplier = matrix[j][i];

            for (int k = 0; k < matrix[j].size(); k++) { //k refers to the current row
                matrix[j][k] -= matrix[i][k]*multiplier;
            }  
        }
    }

    //print the superior triangular matrix
    for (int i = 0; i < matrix.size(); i++) {
        res_matrix.push_back(matrix[i]);
    }
    print_matrix(res_matrix);

    //solve the system
    for (int i = matrix.size() - 1; i >= 0; i--) { //i refers to the current line

        //subtract the previous values found to the line result
        for (int j = matrix.size() - 1; j > i ; j--) { //j refers to the current row
            matrix[i][matrix[i].size() - 1] -= matrix[i][j];
        }

        //calculate the value and put it in the vector
        double curr_res = matrix[i][matrix[i].size() - 1]/matrix[i][i];
        res.push_back(curr_res);

        //substitute the value found in the upper lines of the matrix
        for (int j = i; j >= 0; j --) {
            matrix[j][i] *= curr_res;
        }
    }
 
    return res;
}


int main() {
    std::vector<std::vector<double>> matrix = {
        {7,2,0,24},
        {4,10,1,27},
        {5,-2,8,27}
    };


    std::vector<double> res = gauss_elim(matrix);

    for (int i = 0; i < res.size(); i++) {
        std::cout << "[" <<res[i] << "]" << std::endl;
    }


    return 0;

}
