//
//  Lagrange Interpolation.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 06/11/24.
//

#include "Lagrange Interpolation.hpp"

using namespace std;

int Lagrange() {
    int n;
    
    cout << "Number of data points = ";
    cin >> n;
    
    vector<double> x(n + 1), y(n + 1), l(n + 1, 1.0);
    double xe;
    
    for (int i = 0; i < n; i++) {
        
        cout << "x[" << i << "] = ";
        cin >> x[i];
        
        cout << "f(x)[" << i << "] = ";
        cin >> y[i];
    }
    
    cout << "The value of x to approximate the function = ";
    cin >> xe;
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (i != k) {
                l[k] *= (xe-x[i]) / (x[k] - x[i]);
            }
        }
    }
    
    double p =0.0;
    for (int i = 0; i < n; i++) {
        p += y[i] * l[i];
    }
    
    cout << "The value of f(x) at " << xe << "= " << p << endl;
    
    return 0;
    
}
