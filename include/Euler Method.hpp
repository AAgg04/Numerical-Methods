//
//  Euler Method.hpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 02/11/24.
//

#ifndef Euler_Method_hpp
#define Euler_Method_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

#include "Constant.h"
#include "Polynomial.hpp"

double poly2(double x, double t, int n, int m, const std::vector<vector<double>>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d, vector<double> xp, vector<double> tp);

int Eul();

#endif /* Euler_Method_hpp */
