//
//  Matrix Operations.hpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 28/10/24.
//

#ifndef Matrix_Operations_hpp
#define Matrix_Operations_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

vector<double> MatMul(vector<vector<double>>& mat1, vector<double>& vec, int rows, int cols);

vector<vector<double>> Transpose(vector<vector<double>>& mat1, int rows, int cols);

#endif /* Matrix_Operations_hpp */
