//
//  Matrix Operations.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 28/10/24.
//

#include "Matrix Operations.hpp"

using namespace std;

vector<double> MatMul(vector<vector<double>>& mat1, vector<double>& vec, int rows, int cols) {
    
    vector<double> result(rows, 0);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i] += mat1[i][j] * vec[j];
        }
    }
    return result;
}

vector<vector<double>> Transpose(vector<vector<double>>& mat1, int rows, int cols) {
    vector<vector<double>> mat2(cols, vector<double>(rows, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat2[j][i] = mat1[i][j];
        }
    }
    return mat2;
}
