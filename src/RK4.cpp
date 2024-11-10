//
//  RK4.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 03/11/24.
//

#include "RK4.hpp"

using namespace std;

int RK4() {
    int n, m;
    double t, y, y_new, h;
    double k1, k2, k3, k4;
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
    
    cout << "h = ";
    cin >> h;
    
    cout << "Initial guess of t = ";
    cin >> t;
    
    cout << "Initial guess of y = ";
    cin >> y;

    int i = 0;
    while (i < iter - 1) {
        
        k1 = poly2(y, t, n, m, a, b, c, d, yp, tp);
        
        k2 = poly2(y + 0.5*h*k1, t + 0.5*h, n, m, a, b, c, d, yp, tp);
        
        k3 = poly2(y + 0.5*h*k2, t + 0.5*h, n, m, a, b, c, d, yp, tp);
        
        k4 = poly2(y + h*k3, t + h, n, m, a, b, c, d, yp, tp);
        
        y_new = y + (k1 + 2*k2 + 2*k3 + k4) * (h / 6);
        
        cout << t << "   " << y_new << endl;
        
        if (abs(y_new - y) < tol) {
            break;
        }   else {
            y = y_new;
            t += h;
            i++;
        }
    }
    
    return 0;
}
