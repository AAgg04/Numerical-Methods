//
//  LU Decomposition.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 27/10/24.
//

#include "LU Decomposition.hpp"

using namespace std;

int LU() {
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
    
    vector<vector<double>> l(n, vector<double>(n, 0.0));
    vector<vector<double>> u(n, vector<double>(n, 0.0));
    
    vector<double> x(n);
    vector<double> y(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                double sum = 0.0;
                for (int k = 0; k < i; k++) {
                    sum += l[i][k] * u[k][j];
                }
                u[i][j] = a[i][j] - sum;
                if (i == j) l[i][j] = 1.0; // Diagonal of L is 1
            } else {
                double sum = 0.0;
                for (int k = 0; k < j; k++) {
                    sum += l[i][k] * u[k][j];
                }
                l[i][j] = (a[i][j] - sum) / u[j][j];
            }
        }
    }
    
    cout << "\nLower Triangular Matrix L:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << l[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nUpper Triangular Matrix U:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << u[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < n; i++) {
            y[i] = b[i];
            for (int j = 0; j < i; j++) {
                y[i] -= l[i][j] * y[j];
            }
        }
    
    cout << "The values for matrix Y are:\n";
    for (int i = 0; i < n; i++) {
        cout << "y(" << i << ") = " << y[i] << endl;
    }
    
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= u[i][j] * x[j];
        }
        x[i] /= u[i][i];
    }
    
    cout << "The solution is:\n";
    for (int i = 0; i < n; i++) {
        cout << "x(" << i << ") = " << x[i] << endl;
    }
    
    return 0;
}
