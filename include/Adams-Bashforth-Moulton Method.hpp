//
//  Adams-Bashforth-Moulton Method.hpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 06/11/24.
//

#ifndef Adams_Bashforth_Moulton_Method_hpp
#define Adams_Bashforth_Moulton_Method_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

#include "Constant.h"
#include "Polynomial.hpp"

double poly2(double x, double t, int n, int m, const std::vector<vector<double>>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d, vector<double> xp, vector<double> tp);

int ABM();

#endif /* Adams_Bashforth_Moulton_Method_hpp */
