//
//  Bisection Method.hpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 23/10/24.
//

#ifndef Bisection_Method_hpp
#define Bisection_Method_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>

#include "Constant.h"
#include "Polynomial.hpp"

double poly(double x, int n, int m, const std::vector<double>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d);

int bisection();

#endif /* Bisection_Method_hpp */

