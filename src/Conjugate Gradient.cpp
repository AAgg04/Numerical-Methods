//
//  Conjugate Gradient.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 29/10/24.
//

#include "Conjugate Gradient.hpp"

using namespace std;

int ConGr() {
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
    vector<double> v(n, 0);
    double t;
    double s;
    
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
    
    c = MatMul(a, x, n, n);
    
    for (int i = 0; i < n; i++) {
        r[i] = b[i] - c[i];
    }
    
    vector<vector<double>> rm(n, vector<double>(1));
            for (int i = 0; i < n; ++i) {
                rm[i][0] = r[i];
            }
    
    for (int i = 0; i < n; i++) {
        v[i] = r[i];
    }
    
    vector<vector<double>> vm(n, vector<double>(1));
            for (int i = 0; i < n; ++i) {
                vm[i][0] = v[i];
            }
    
    int k = 0;
    do {
        
        vector<vector<double>> rt = Transpose(rm, n, 1);
        vector<vector<double>> vt = Transpose(vm, n, 1);
                double num = MatMul(rt, r, 1, n)[0];
                vector<double> Av = MatMul(a, v, n, n);
                double den = MatMul(vt, Av, 1, n)[0];
        
        t =  num / den;
        
        for (int i = 0; i < n; ++i) {
                    x[i] = x[i] + t * v[i];
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
            
            for (int i = 0; i < n; ++i) {
                r[i] = r[i] - t * Av[i];
                    }
            
            vector<vector<double>> rm1(n, vector<double>(1));
                    for (int i = 0; i < n; ++i) {
                        rm1[i][0] = r[i];
                    }
            
            vector<vector<double>> rt1 = Transpose(rm1, n, 1);
                    double num1 = MatMul(rt1, r, 1, n)[0];
            
            s =  num1 / num;
            
            for (int i = 0; i < n; ++i) {
                v[i] = r[i] + s * v[i];
                    }
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
