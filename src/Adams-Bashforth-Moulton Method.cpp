//
//  Adams-Bashforth-Moulton Method.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 06/11/24.
//

#include "Adams-Bashforth-Moulton Method.hpp"

using namespace std;

int ABM() {
    int n, m;
    double t, y, y_new, h;
    double k1, k2, k3, k4;
    double y_rk[4], t_rk[4];
    double y_i, y_i1, y_i2, y_i3, t_i, t_i1, t_i2, t_i3, f_i, f_i1, f_i2, f_i3;
    double y_1i, f_1i, t_1i;
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
    
    y_rk[0] = y;
    t_rk[0] = t;
    
    int i = 0;
    while (i < 4) {
        
        k1 = poly2(y, t, n, m, a, b, c, d, yp, tp);
        
        k2 = poly2(y + 0.5*h*k1, t + 0.5*h, n, m, a, b, c, d, yp, tp);
        
        k3 = poly2(y + 0.5*h*k2, t + 0.5*h, n, m, a, b, c, d, yp, tp);
        
        k4 = poly2(y + h*k3, t + h, n, m, a, b, c, d, yp, tp);
        
        y_new = y + (k1 + 2*k2 + 2*k3 + k4) * (h / 6);
        
        y = y_new;
        t += h;
        y_rk[i] = y_new;
        t_rk[i] = t;
        i++;
        
    }
    
    y_i3 = y_rk[0]; t_i3 = t_rk[0];
    y_i2 = y_rk[1]; t_i2 = t_rk[1];
    y_i1 = y_rk[2]; t_i1 = t_rk[2];
    y_i = y_rk[3]; t_i = t_rk[3];
    
    int j = 0;
    while (j < iter - 1) {
        f_i3 = poly2(y_i3, t_i3, n, m, a, b, c, d, yp, tp);
        f_i2 = poly2(y_i2, t_i2, n, m, a, b, c, d, yp, tp);
        f_i1 = poly2(y_i1, t_i1, n, m, a, b, c, d, yp, tp);
        f_i = poly2(y_i, t_i, n, m, a, b, c, d, yp, tp);
        
        y_1i = y_i + (h/24) * (55*f_i - 59*f_i1 + 37*f_i2 - 2*f_i3);
        t_1i = t_i + h;
        
        f_1i = poly2(y_1i, t_1i, n, m, a, b, c, d, yp, tp);
        
        y_new = y_i + (h/24) * (f_i2 - 5*f_i1 + 19*f_i + 9*f_1i);
        
        cout << t_1i << "   " << y_new << endl;
        
        if ((y_new - y_i) <= tol) {
            break;
        }   else {
            y_i3 = y_i2; t_i3 = t_i2;
            y_i2 = y_i1; t_i2 = t_i1;
            y_i1 = y_i; t_i1 = t_i;
            y_i = y_new; t_i = t_1i;
            
            j++;
        }
    }
    
    return 0;
}
