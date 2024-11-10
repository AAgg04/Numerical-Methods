//
//  Fixed point iteration.hpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 09/11/24.
//

#ifndef Fixed_point_iteration_hpp
#define Fixed_point_iteration_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

#include "Constant.h"
#include "Polynomial.hpp"

double polyn(const std::vector<double>& x, int v, int n, int m, const std::vector<std::vector<std::vector<double>>>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d);

void FPI();

#endif /* Fixed_point_iteration_hpp */
