//
//  Trapezoidal method(CNC).cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 07/11/24.
//

#include "Trapezoidal method(CNC).hpp"

using namespace std;

int Trapezoidal() {
    
    int n, m, v;
    vector<double> p;
    vector<double> a, c, d;
    vector<string> b;
    double x, y, h, sum, xf, result;
    
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
    
    cout << "number of subintervals = ";
    cin >> v;
    
    cout << "Lower bound = ";
    cin >> x;
    
    cout << "Upper bound = ";
    cin >> y;
    
    h = (y - x) / v;
    
    double fx = poly(x, n, m, a, b, c, d);
    double fy = poly(y, n, m, a, b, c, d);
    
    sum = (fx + fy) / 2;
    
    for (int i = 1; i < v; ++i) {
        xf = x + i * h;
        double f = poly(xf, n, m, a, b, c, d);
        sum += f;
    }
    
    result = h * sum;
    
    cout << "Approximated integral value = " << result << endl;
    
    return 0;
}
