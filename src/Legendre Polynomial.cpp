//
//  Legendre Polynomial.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 07/11/24.
//

#include "Legendre Polynomial.hpp"

using namespace std;

double factorial(int n) {
    double fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

double Leg(double x, int n) {
    double p = 0.0;
    for (int r = 0; r <= n / 2; r++) {
        p += (pow(-1, r) * factorial(2 * (n - r)) * pow(x, n - 2 * r)) /
             (pow(2, n) * factorial(r) * factorial(n - 2 * r) * (n - r));
    }
    
    cout << "Leg =" << p << endl;
    return p;
}

double Leg1(double x, int n) {
    double denom = 1 - pow(x, 2) + epsilon;  // Increased epsilon in denominator
    if (fabs(denom) < epsilon) {
        cout << "Leg1: Adjusting denominator to avoid division by zero." << endl;
        denom = epsilon;
    }
    return (n * (Leg(x, n - 1) - x * Leg(x, n))) / denom;
}

vector<double> Nodes(int n) {
    vector<double> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = cos(pi * (2 * i + 1) / (2 * n));  // Chebyshev nodes
    }
    return nodes;
}

vector<double> Rhap(int n) {
    vector<double> root(n);
    vector<double> initial_guesses = Nodes(n);  // Store nodes to avoid recalculating
    
    for (int k = 0; k < n; ++k) {
        vector<double> x(iter);
        x[0] = initial_guesses[k];  // Initial guess from Chebyshev nodes
        int i = 1;
        
        while (i < iter) {
            double fx = Leg(x[i - 1], n);
            double fpx = Leg1(x[i - 1], n);
            
            if (fabs(fpx) < tol) {
                cout << "Small derivative encountered; breaking." << endl;
                break;
            }
            
            x[i] = x[i - 1] - fx / fpx;
            cout << "Iteration " << i << ": x = " << x[i] << endl;
            
            if (fabs(x[i] - x[i - 1]) < tol) {
                root[k] = x[i];
                break;
            }
            i++;
        }
        
        if (i == iter) {
            cout << "Maximum iterations reached without convergence for root " << k << endl;
        }
    }
    
    return root;
}

vector<double> weight(const vector<double>& root, int n) {
    vector<double> w(n);
    for (int i = 0; i < n; ++i) {
        double leg1_val = Leg1(root[i], n);
        
        if (fabs(leg1_val) < epsilon) {
            cout << "Warning: Small derivative encountered in weight calculation; setting to finite value." << endl;
            w[i] = 1e6;  // Use a large finite number as a fallback
        } else {
            w[i] = 2 / ((1 - pow(root[i], 2) + epsilon) * pow(leg1_val, 2));
        }
        cout << "weight[" << i << "] = " << w[i] << endl;
    }
    return w;
}
