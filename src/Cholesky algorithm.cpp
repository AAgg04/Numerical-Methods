//
//  Cholesky algorithm.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 27/10/24.
//

#include "Cholesky algorithm.hpp"

using namespace std;

int ChoAl() {
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
    vector<vector<double>> l_t(n, vector<double>(n, 0.0));
    vector<double> x(n);
    vector<double> y(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j) {
                double sum = 0;
                for (int k = 0; k < i; k++) {
                    sum += pow(l[i][k], 2);
                }
                l[i][i] = sqrt(a[i][i] - sum);
            } else {
                double sum = 0;
                for (int k = 0; k < j; k++) {
                    sum += l[i][k] * l[j][k];
                }
                l[i][j] = (a[i][j] - sum) / l[j][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            l_t[j][i] = l[i][j];
        }
    }

    cout << "\nTriangular Matrix L:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << l[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nTranspose Triangular Matrix L^T:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << l_t[i][j] << " ";
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
            x[i] -= l_t[i][j] * x[j];
        }
        x[i] /= l_t[i][i];
    }

    cout << "The solution is:\n";
    for (int i = 0; i < n; i++) {
        cout << "x(" << i << ") = " << x[i] << endl;
    }

    return 0;
}
