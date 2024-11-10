//
//  Steepest Descent Technique.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 28/10/24.
//

#include "Steepest Descent Technique.hpp"

using namespace std;

int SteDe() {
    int n;
    cout << "Enter the number of Variables: ";
    cin >> n;
    
    vector<vector<double>> a(n, vector<double>(n));
    cout << "Enter the elements of the matrix A:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    
    vector<double> b(n);
    cout << "Enter the elements of the matrix B:\n";
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    vector<double> x(n);
    cout << "Enter the elements of the matrix X (initial Guess):\n";
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    
    vector<double> c(n);
    vector<double> r(n, 0);
    double w;
    int g = 0;
    
    for (int i = 0; i < n; i++) {
        if (x[i] != 0) {
            g++;
        }
    }
    
    if (g > 0) {
        vector<vector<double>> xm(n, vector<double>(1));
        for (int i = 0; i < n; ++i) {
            xm[i][0] = x[i];
        }
        
        vector<double> Ax = MatMul(a, x, n, n);
        vector<vector<double>> xt = Transpose(xm, n, 1);
        double pd = MatMul(xt, Ax, 1, n)[0];
        
        if (pd > 0) {
            
            int k = 0;
            do {
                c = MatMul(a, x, n, n);
                
                for (int i = 0; i < n; i++) {
                    r[i] = b[i] - c[i];
                }
                
                vector<vector<double>> rm(n, vector<double>(1));
                for (int i = 0; i < n; ++i) {
                    rm[i][0] = r[i];
                }
                
                vector<vector<double>> rt = Transpose(rm, n, 1);
                double num = MatMul(rt, r, 1, n)[0];
                vector<double> Ar = MatMul(a, r, n, n);
                double den = MatMul(rt, Ar, 1, n)[0];
                
                w =  num / den;
                
                for (int i = 0; i < n; ++i) {
                    x[i] = x[i] + w * r[i];
                }
                
                for (int i = 0; i < n; i++) {
                    cout << "x = "<< x[i] << endl;
                }
                
                cout << "Iteration " << k << ": ";
                for (int i = 0; i < n; i++) {
                    cout << x[i] << " ";
                }
                cout << "]" << endl;
                
                double f = 0;
                for (int i = 0; i < n; i++) {
                    f += x[i];
                }
                double norm = sqrt(f);
                if (norm < tol) {
                    break;
                }   else {
                    k++;
                }
                
            } while (k < iter);
        }   else    {
            cout << "The Matrix A is not positive-definite" << endl;
        }
        
    }   else {
        cout << "Enter non-zero elements to check positive-definite condition of matrix A" <<  endl;
    }
    
    return 0;
}
