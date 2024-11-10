//
//  Cubic Spline Interpolation.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 07/11/24.
//

#include "Cubic Spline Interpolation.hpp"

using namespace std;

int CSI() {
    
    int n;
    
    cout << "Number of data points = ";
    cin >> n;
    
    vector<double> x(n), y(n);
    vector<double> h(n-1), a(n), b(n-1), c(n, 0.0), d(n-1);
    vector<double> l(n, 1.0), mu(n, 0.0), z(n, 0.0);
    double xe;
    
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        
        cout << "y[" << i << "] = ";
        cin >> y[i];
    }
    
    cout << "The value of x to approximate the function = ";
    cin >> xe;
    
    for (int i = 0; i < n-1; i++) {
        h[i] = x[i+1] - x[i];
        a[i] = y[i];
    }
    
    vector<double> s(n-1);
    for (int i = 1; i < n - 1; i++) {
        s[i] = (3/h[i]) * (a[i+1] - a[i]) - (3/h[i-1]) * (a[i] - a[i-1]);
    }
    
    l[0] = 1;
    mu[0] = 0;
    z[0] = 0;
    
    for (int i = 1; i < n - 1; i++) {
        
        l[i] = 2 * (x[i+1] - x[i-1]) - h[i-1] * mu[i-1];
        mu[i] = h[i] / l[i];
        z[i] = (s[i] - h[i-1] * z[i-1]) / l[i];
        
    }
    
    l[n-1] = 1;                 //natural boundaries
    z[n-1] = 0;
    c[n-1] = 0;
    
    for (int i = n-2; i >= 0; i--) {
        
        c[i] = z[i] - mu[i] * c[i+1];
        b[i] = ((a[i+1] - a[i]) / h[i]) - (h[i] * (c[i+1] + 2*c[i])) / 3;
        d[i] = (c[i+1] - c[i]) / (3 * h[i]);
    }
    
    double result = 0.0;
    for (int i = 0; i < n - 1; i++) {
        if (xe >= x[i] && xe <= x[i+1]) {
            result = a[i] + b[i] * (xe - x[i]) + c[i] * pow(xe - x[i], 2) + d[i] * pow(xe - x[i], 3);
            break;
        }
    }
    
    cout << "The interpolated value at x = " << xe << " is " << result << endl;
    
    return 0;
}
