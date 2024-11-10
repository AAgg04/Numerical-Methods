////
////  test.cpp
////  Numerical Methods
////
////  Created by Amogh Aggarwal on 25/10/24.
////
//
//#include "test.hpp"
//
//using namespace std;
//
//int example() {
//    double sum;
//    int n, m, v;
//    vector<vector<vector<double>>> a;
//    vector<string> b;
//    vector<double> c, d, x;
//
//    cout << "Number of variables = ";
//    cin >> v;
//
//    cout << "Degree of the polynomial = ";
//    cin >> n;
//
//    cout << "Number of functions = ";
//    cin >> m;
//
//    // Resize the matrix and vectors according to the input sizes
//    a.resize(v, vector<vector<double>>(v, vector<double>(n + 1)));
//    b.resize(m);
//    c.resize(m);
//    d.resize(m);
//    x.resize(v);  // Resize x to hold v values
//
//    // Fill matrix a with coefficients
//    for (int i = 0; i < v; i++) {
//        for (int j = 0; j < v; j++) {  // Only loop up to v, not (n + 1 + v)
//            for (int degree = 0; degree <= n; degree++) {
//                cout << "Enter coefficient for term (x_" << i << " * x_" << j << ")^" << degree << ": ";
//                cin >> a[i][j][degree];
//            }
//        }
//    }
//        
//
//    // Fill vectors b, c, and d with corresponding values
//    for (int i = 0; i < m; i++) {
//        cout << "Enter the name of the function, coefficient of the function, and variable coefficient: ";
//        cin >> b[i] >> c[i] >> d[i];
//    }
//
//    // Fill vector x with values
//    for (int i = 0; i < v; i++) {
//        cout << "Enter the value of x[" << i << "] = ";
//        cin >> x[i];
//    }
//
//    // Call the polyn function with the provided inputs
//    sum = polyn(x, v, n, m, a, b, c, d);
//
//    // Output the result
//    cout << "Resulting sum: " << sum << endl;
//
//    return 0;
//}
