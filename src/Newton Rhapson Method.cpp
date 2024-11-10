//
//  Newton Rhapson Method.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 24/10/24.
//

#include "Newton Rhapson Method.hpp"

using namespace std;

double NR(double x) {
    return x * x - 3;  // Function f(x) = x^2 - 3
}

double NR1(double x) {
    return 2 * x;  // Derivative f'(x) = 2x
}

int NewRhap() {
    vector<double> x(iter);
    
    x[0] = 1;  // Initial guess
    
    int i = 1;
    while (true) {
        x[i] = x[i-1] - NR(x[i-1]) / NR1(x[i-1]);
        cout << "Iteration " << i << ": x = " << x[i] << endl;
        
        if (abs(x[i] - x[i-1]) < tol) {  // Convergence criterion
            break;
        }
        i++;
        if (i >= iter) {  // Prevent overflow
            cout << "Maximum iterations reached." << endl;
            break;
        }
    }
    
    return 0;
}
