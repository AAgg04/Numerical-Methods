//
//  Gauss Elimination.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 27/10/24.
//

#include "Gauss Elimination.hpp"

using namespace std;

int GauEli() {
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

    for (int k = 0; k < n; k++) {
        int p = k;
        for (int i = k + 1; i < n; i++) {
            if (abs(a[i][k]) > abs(a[p][k])) {
                p = i;
            }
        }
        
        if (p != k) {
            swap(a[k], a[p]);
            swap(b[k], b[p]);
        }

        for (int i = k + 1; i < n; i++) {
            double q = a[i][k] / a[k][k];
            for (int j = k; j < n; j++) {
                a[i][j] -= q * a[k][j];
            }
            b[i] -= q * b[k];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    cout << "The solution is:\n";
    for (int i = 0; i < n; i++) {
        cout << "x(" << i << ") = " << x[i] << endl;
    }

    return 0;
}
