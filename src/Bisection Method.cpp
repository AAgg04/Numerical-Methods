#include "Bisection Method.hpp"

using namespace std;

int bisection() {
    
    int n, m;
    vector<double> p(iter + 1);
    vector<double> a, c, d;
    vector<string> b;
    double x_0;
    double y_0;
    
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

    cout << "Enter the initial guesses" << endl;
    cin >> x_0 >> y_0;
    
    vector<double> x(iter + 1, x_0);
    vector<double> y(iter + 1, y_0);
    
    // Check if the initial guesses are valid
    if (poly(y_0, n, m, a, b, c, d) * poly(x_0, n, m, a, b, c, d) < 0) {
        for (int i = 0; i < iter; i++) {
            double p = (x[i] + y[i]) / 2; // Midpoint of the interval
            double xi = x[i];

            // Check if the solution is found within the tolerance
            if (poly(p, n, m, a, b, c, d) == 0 || abs(y[i] - x[i]) < tol) {
                cout << "Root approximation: p = " << p << endl;
                break;
            }
            // Update the intervals based on the sign of f(p)
            else if (poly(p, n, m, a, b, c, d) * poly(xi, n, m, a, b, c, d) > 0) {
                x[i + 1] = p;  // Update the left bound
                y[i + 1] = y[i]; // Keep the right bound unchanged
                cout << "p1: " << p << endl;
            } else {
                y[i + 1] = p;  // Update the right bound
                x[i + 1] = x[i]; // Keep the left bound unchanged
                cout << "p2: " << p << endl;
            }
        }
    } else {
        cout << "The function does not have a root in the given interval." << endl;
    }
    return 0;
}
