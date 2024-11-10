//
//  Secant Method.hpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 24/10/24.
//

#ifndef Secant_Method_hpp
#define Secant_Method_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map> 

#include "Constant.h"
#include "Polynomial.hpp"
#include "test.hpp"

double poly(double x, int n, int m, const std::vector<double>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d);

int Sec();

#endif /* Secant_Method_hpp */
