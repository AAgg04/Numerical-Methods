//
//  Newton’s divided difference method.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 06/11/24.
//

#include "Newton’s divided difference method.hpp"

using namespace std;

int NDDM() {
    int n;
    
    cout << "Number of data points = ";
    cin >> n;
    
    vector<vector<double>> F(n, vector<double>(n, 0.0));
    vector<double> x(n);
    double xe, P;
    
    for (int i = 0; i < n; i++) {
        
        cout << "x[" << i << "] = ";
        cin >> x[i];
        
        cout << "f(x)[" << i << "] = ";
        cin >> F[i][0];
    }
    
    cout << "The value of x to approximate the function = ";
    cin >> xe;
    
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n-j; i++) {
            F[i][j] = (F[i+1][j-1] - F[i][j-1]) / (x[i+j] - x[i]);
        }
    }
    
    P = F[0][0];
    double mul = 1.0;
    for (int j = 1; j < n; j++) {
        mul *= (xe - x[j-1]);
        P += F[0][j] * mul;
    }
    
    cout << "The interpolated value at x = " << xe << " is " << P << endl;
    
    return 0;
}
