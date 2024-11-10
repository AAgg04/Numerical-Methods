//
//  RK45.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 05/11/24.
//

#include "RK45.hpp"

using namespace std;

int RK45() {
    int n, m;
    double t, t_max, y, y_RK4, y_RK5, h, del, R;
    double k1, k2, k3, k4, k5, k6;
    vector<double> p(iter + 1);
    vector<double> c, d, yp, tp;
    vector<string> b;
    
    cout << "Enter the degree of the polynomial" << endl;
    cin >> n;
    
    cout << "Enter the number of functions" << endl;
    cin >> m;
    
    vector<vector<double>> a(n + 1, vector<double>(n + 1));
    b.resize(m);
    c.resize(m);
    d.resize(m);
    yp.resize(m);
    tp.resize(m);
    
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << "Enter the coefficient for a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < m; i++) {
        cout << "Enter the name of the function and coefficient of the function" << endl;;
        cin >> b[i] >> c[i];
        
        cout << "Enter the coefficient of the variables inside the function and their power" << endl;
        cin >> d[i] >> yp[i] >> tp[i];
    }
    
    cout << "Step size(h) = ";
    cin >> h;
    
    cout << "Initial guess of t = ";
    cin >> t;
    
    cout << "Maximum range for t = ";
    cin >> t_max;
    
    cout << "Initial guess of y = ";
    cin >> y;

    int i = 0;
    while (t < t_max) {
        
        h = min(h, t_max-t);
        
        k1 = h * poly2(y, t, n, m, a, b, c, d, yp, tp);
        
        k2 = h * poly2(y + k1/4.0, t + h/4.0, n, m, a, b, c, d, yp, tp);
        
        k3 = h * poly2(y + (3.0/32.0)*k1 + (9.0/32.0)*k2, t + (3.0/8.0)*h, n, m, a, b, c, d, yp, tp);
        
        k4 = h * poly2(y + (1932.0/2197.0)*k1 - (7200.0/2197.0)*k2 + (7296.0/2197.0)*k3, t + (12.0/13.0)*h, n, m, a, b, c, d, yp, tp);
        
        k5 = h * poly2(y + (439.0/216.0)*k1 - 8.0*k2 + (3680.0/513.0)*k3 - (845.0/4104.0)*k4, t + h, n, m, a, b, c, d, yp, tp);
        
        k6 = h * poly2(y - (8.0/27.0)*k1 + 2.0*k2 - (3544.0/2565.0)*k3 + (1859.0/4104.0)*k4 - (11.0/40.0)*k5, t + h/2.0, n, m, a, b, c, d, yp, tp);
        
        y_RK4 = y + ((25.0/216.0)*k1 + (1408.0/2565.0)*k3 + (2197.0/4104.0)*k4 - (1.0/5.0)*k5);
        
        y_RK5 = y + ((16.0/135.0)*k1 + (6656.0/12825.0)*k3 + (28561.0/56430.0)*k4 - (9.0/50.0)*k5 + (2.0/55.0)*k6);
        
        R =abs(y_RK4 - y_RK5) / h;
        
        del = 0.84*pow(tol/R, 1.0/4.0);
        
        if (R <= tol) {
            t += h;
            y = y_RK4;
            i++;
            cout << t << "   " << y_RK4 << endl;
            h *= del;
        } else {
            h *= del;
        }
    }
    
    return 0;
}
