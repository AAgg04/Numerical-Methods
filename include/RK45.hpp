//
//  RK45.hpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 05/11/24.
//

#ifndef RK45_hpp
#define RK45_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

#include "Constant.h"
#include "Polynomial.hpp"

double poly2(double x, double t, int n, int m, const std::vector<vector<double>>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d, vector<double> xp, vector<double> tp);

int RK45();

#endif /* RK45_hpp */
