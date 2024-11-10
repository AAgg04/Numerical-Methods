//
//  Trapezoidal method(CNC).hpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 07/11/24.
//

#ifndef Trapezoidal_method_CNC__hpp
#define Trapezoidal_method_CNC__hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>

#include "Constant.h"
#include "Polynomial.hpp"

double poly(double x, int n, int m, const std::vector<double>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d);

int Trapezoidal();

#endif /* Trapezoidal_method_CNC__hpp */
