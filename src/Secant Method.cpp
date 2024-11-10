//
//  Secant Method.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 24/10/24.
//

#include "Secant Method.hpp"

using namespace std;

int Sec() {
    
    int n, m;
    vector<double> x(iter, 0);
    vector<double> a, c, d;
    vector<string> b;
    double x_i, x_ii, fx0, fx1;
    
    cout << "Enter the degree of the polynomial" << endl;
    cin >> n;
    
    cout << "Enter the number of functions" << endl;
    cin >> m;
    
    a.resize(n + 1);
    b.resize(m);
    c.resize(m);
    d.resize(m);
    
    for (int i = 0; i <= n; i++) {
        cout << "Enter the coefficient of the variable x^" << i << endl;
        cin >> a[i];
    }
    
    for (int i = 0; i < m; i++) {
        cout << "Enter the name of the function and coefficient of the function and coefficient of the variable inside" << endl;;
        cin >> b[i] >> c[i] >> d[i];
    }
    
    cout << "Enter initial guesses: ";
    cin >> x[0] >> x[1];
    
    int i = 1;
    while (true) {
        x_i = x[i];
        x_ii = x[i-1];
//        cout << typeid(x_i).name() << endl;
        cout << "x_i" << x_i << endl;
        cout << "x_ii" << x_ii << endl;
        fx0 = poly(x_ii, n, m, a, b, c, d);
        cout << "fx0 = " << fx0 << endl;
        fx1 = poly(x_i, n, m, a, b, c, d);
        cout << "fx1 = " << fx1 << endl;
        double denominator = fx0 - fx1;
        cout << "denominator = " << denominator << endl;
        
        if (fabs(denominator) < tol) {
            cout << "Division by zero detected. Aborting." << endl;
            break;
        } else {
            x[i + 1] = x[i] - ((x[i - 1] - x[i]) / denominator) * fx1;
            cout << "x = " << x[i + 1] << endl;
            
            if (fabs(x[i] - x[i - 1]) < tol) {
                exit(0);
            } else if (i + 1 >= iter) {
                cout << "Maximum iterations reached." << endl;
                break;
            }   else {
                i++;
            }
        }
    }
    return 0;
}
