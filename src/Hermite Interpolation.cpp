//
//  Hermite Interpolation.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 07/11/24.
//

#include "Hermite Interpolation.hpp"

using namespace std;

int Hermite() {
    int n;
    
    cout << "Number of data points = ";
    cin >> n;
    
    vector<vector<double>> F(2*n, vector<double>(2*n, 0.0));
    vector<double> x(2*n), f(2*n), f1(n);
    double xe, H;
    
    for (int i = 0; i < n; i++) {
        
        cout << "x[" << i << "] = ";
        cin >> x[2*i];
        x[2*i + 1] = x[2*i];
        
        cout << "f(x)[" << i << "] = ";
        cin >> f[2*i];
        f[2*i + 1] = f[2*i];
        
        cout << "f'(x)[" << i << "] = ";
        cin >> f1[i];
    }
    
    cout << "The value of x to approximate the function = ";
    cin >> xe;
    
    for (int i = 0; i < 2*n; i++) {
        F[i][0] = f[i];
        if (i % 2 == 1) {
            F[i][1] = f1[i/2];
        } else if (i > 0) {
            F[i][1] = (F[i][0] - F[i-1][0]) / (x[i] - x[i-1]);
        }
    }
    
    for (int j = 2; j < 2*n; j++) {
        for (int i = 0; i < 2*n - j; i++) {
            F[i][j] = (F[i+1][j-1] - F[i][j-1]) / (x[i+j] - x[i]);
        }
    }
    
    H = F[0][0];
    double mul = 1.0;

    for (int j = 1; j < 2*n; j++) {
        mul *= (xe - x[j-1]);
        H += F[0][j] * mul;
    }
    
    
    cout << "The interpolated value at x = " << xe << " is " << H << endl;
    
    return 0;
    
}
