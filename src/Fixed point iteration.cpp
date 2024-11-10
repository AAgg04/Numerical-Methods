//
//  Fixed point iteration.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 09/11/24.
//

#include "Fixed point iteration.hpp"

using namespace std;

void FPI() {
    int n, m, v;
    vector<vector<vector<double>>> a;
    vector<string> b;
    vector<double> c, d, x;

    cout << "Number of variables = ";
    cin >> v;

    cout << "Degree of the polynomial = ";
    cin >> n;

    cout << "Number of functions = ";
    cin >> m;

    a.resize(v, vector<vector<double>>(v, vector<double>(n + 1)));
    b.resize(m);
    c.resize(m);
    d.resize(m);
    x.resize(v);

    // Input coefficients for the polynomial terms
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            for (int degree = 0; degree <= n; degree++) {
                cout << "Enter coefficient for term (x_" << i << " * x_" << j << ")^" << degree << ": ";
                cin >> a[i][j][degree];
            }
        }
    }

    // Input additional function parameters if applicable
    for (int i = 0; i < m; i++) {
        cout << "Enter the name of the function, coefficient of the function, and variable coefficient: ";
        cin >> b[i] >> c[i] >> d[i];
    }

    // Input initial values for variables
    for (int i = 0; i < v; i++) {
        cout << "Enter the value of x[" << i << "] = ";
        cin >> x[i];
    }

    vector<vector<double>> xe(v, vector<double>(iter, 0));  // Track values per iteration
    double prev_sum = 0, curr_sum = 0;

    // Start iteration
    for (int i = 0; i < iter; i++) {
        curr_sum = 0;

        // Calculate new values for each variable and accumulate the sum
        for (int j = 0; j < v; j++) {
            xe[j][i] = polyn(x, v, n, m, a, b, c, d); // Calculate new value for x[j]
            curr_sum += xe[j][i];
        }

        cout << "Iteration " << i << ", sum: " << curr_sum << endl;

        // Convergence check
        if (i > 0 && abs(curr_sum - prev_sum) < tol) {
            cout << "Convergence reached at iteration " << i << endl;
            break;
        }

        // Update x with new values for the next iteration
        for (int j = 0; j < v; j++) {
            x[j] = xe[j][i];
        }

        prev_sum = curr_sum; // Update prev_sum for the next iteration's convergence check
    }
}
