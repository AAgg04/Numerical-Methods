//
//  Heun Method.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 02/11/24.
//

#include "Heun Method.hpp"

using namespace std;

int Heun() {
    
    //Gnuplot gp;
    int n, m;
    double t, y, ypd, f, fp, t_new, y_new, h;
    vector<double> p(iter + 1);
    vector<double> c, d, yp, tp;
    vector<string> b;
    std::vector<std::pair<double, double>> data;
    
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
    
    cout << "h = ";
    cin >> h;
    
    cout << "Initial guess of t = ";
    cin >> t;
    
    cout << "Initial guess of y = ";
    cin >> y;

    int i = 0;
    while (i < iter - 1) {
        
        //f = 2 - exp(-4 * t) - 2 * y;
        f = poly2(y, t, n, m, a, b, c, d, yp, tp);
        
        t_new = t + h;
        
        ypd = y + h * f;
        
        //fp = 2 - exp(-4 * t_new) - 2 * ypd;
        fp = poly2(ypd, t_new, n, m, a, b, c, d, yp, tp);
        
        y_new = y + h * (f - fp) / 2;
        
        cout << y_new << endl;
        //data.push_back(std::make_pair(i, y_new));
        
        if (abs(y_new - y) < tol) {
            break;
        }   else {
            y = y_new;
            t = t_new;
            i++;
        }
    }
//    gp << "set title 'Heun Method Solution'\n";
//        gp << "set xlabel 'Time (t)'\n";
//        gp << "set ylabel 'y(t)'\n";
//        gp << "plot '-' with linespoints title 'Approximation'\n";
//        gp.send1d(data);
    
    return 0;
}

