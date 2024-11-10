//
//  Simpson’s one-third rule(CNC).cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 07/11/24.
//

#include "Simpson’s one-third rule(CNC).hpp"

using namespace std;

int Simpson13() {
    
    int n, m, v;
    vector<double> p;
    vector<double> a, c, d;
    vector<string> b;
    double x, y, h, sum, result, f;
    
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
    if (v % 2 != 0) {
        cout << "Error: Simpson’s one-third rule requires an even number of subintervals." << endl;
        return -1;
    }
    
    cout << "Lower bound = ";
    cin >> x;
    
    cout << "Upper bound = ";
    cin >> y;
    
    h = (y - x) / v;
    
    double fx = poly(x, n, m, a, b, c, d);
    double fy = poly(y, n, m, a, b, c, d);
    
    sum = fx + fy;
    
    for (int i = 1; i < v; i += 2) {
        f = poly(x+i*h, n, m, a, b, c, d);
        sum += 4 * f;
    }
    
    for (int i = 2; i < v-1; i += 2) {
        f = poly(x+i*h, n, m, a, b, c, d);
        sum += 2 * f;
    }
    
    result = h * sum / 3;
    
    cout << "Approximated integral value = " << result << endl;
    
    return 0;
}
