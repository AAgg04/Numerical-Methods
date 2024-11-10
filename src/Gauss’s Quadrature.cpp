//
//  Gauss’s Quadrature.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 07/11/24.
//

#include "Gauss’s Quadrature.hpp"

using namespace std;

int GQ() {
    
    int n, m, v;
    vector<double> p;
    vector<double> a, c, d;
    vector<string> b;
    double x, y, t;
    
    cout << "Degree of the polynomial = ";
    cin >> n;
    
    cout << "Number of functions = ";
    cin >> m;
    
    a.resize(n + 1);
    b.resize(m);
    c.resize(m);
    d.resize(m);
    
    for (int i = 0; i <= n; i++) {
        cout << "x^" << i << " = ";
        cin >> a[i];
    }
    
    for (int i = 0; i < m; i++) {
        cout << "Enter the name of the function and coefficient of the function and coefficient of the variable inside" << endl;;
        cin >> b[i] >> c[i] >> d[i];
    }
    
    cout << "Number of points = ";
    cin >> v;
    
    cout << "Lower bound = ";
    cin >> x;
    
    cout << "Upper bound = ";
    cin >> y;
    
    vector<double> root = Rhap(v);
        vector<double> w = weight(root, v);
    
    double integral = 0.0;
    
    for (int i = 0; i < v; i++) {
        t = ((y - x) / 2) * root[i] + (x + y) / 2;
        
        integral += w[i] * poly(t, n, m, a, b, c, d);
    }
    
    integral *= (y - x) / 2;
    
    cout << "Integral = "<< integral << endl;
    
    return 0;
}
