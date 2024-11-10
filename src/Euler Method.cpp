//
//  Euler Method.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 02/11/24.
//

#include "Euler Method.hpp"

using namespace std;

int Eul() {
    
    int n, m;
    vector<double> p(iter + 1);
    vector<double> c, d, yp, tp;
    vector<string> b;
    double t, y, h, f, y_new;
    
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
    
    h = 0.1;
    t = 0;
    y = 1;

    int i = 0;
    while (i < iter - 1) {
        //f = 2 - exp(-4 * t) - 2 * y;
        f = poly2(y, t + 0.5, n, m, a, b, c, d, yp, tp);
        cout << f << endl;
        t += h;
        y_new = y + h * f;
        
        cout << y << endl;
        
        if (abs(y_new - y) < tol) {
            break;
        }   else {
            y = y_new;
            i++;
        }
    }
    
    return 0;
}


