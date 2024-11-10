//
//  Successive over relaxation.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 27/10/24.
//

#include "Successive over relaxation.hpp"

using namespace std;

int SOR() {
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
    cout << "Enter th elements of the matrix B:\n";
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    vector<double> x(n);
    cout << "Enter the elements of the matrix x(Initial Guess):\n";
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    
    vector<double> x_new(n);
    
    int w;
    
    while (true) {
        cout << "Enter a value for relaxation factor between 0 and 2: " <<  endl;
            cin >> w;

            if (w > 0 && w < 2) {
                cout << "Value accepted: " << w << endl;
                break; // Exit the loop
            } else {
                cout << "Invalid value. Please reenter." << endl;
            }
        }
    
    cout << "Iteration results:\n";
    for (int k = 0; k < iter; k++) {
        bool has_converged = true;
        
        for (int i = 0; i < n; i++) {
            double sum = 0;
            
            for (int j = 0; j < i; ++j) {
                if (i != j) {
                    sum += a[i][j] * x[j];
                }
            }
            for (int j = i+1; j < n; ++j) {
                if (i != j) {
                    sum += a[i][j] * x[j];
                }
            }
            x_new[i] = (1 - w)*x[i] + w * (b[i] - sum) / a[i][i];
            
            if (abs(x_new[i] - x[i]) > tol) {
                has_converged = false;
            }
            x[i] = x_new[i];
        }
        
        cout << "Iteration " << k + 1 << ": ";
        cout << fixed << setprecision(6);
        for (int i = 0; i < n; i++) {
            cout << "x[" << i << "] = " << x[i] << " ";
        }
        
        if (has_converged) {
            cout << "Convergence achieved in " << k + 1 << " iterations.\n";
            break;
        }
    }
    
    return 0;
}

