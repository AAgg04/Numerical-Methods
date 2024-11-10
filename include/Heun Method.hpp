//
//  Heun Method.hpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 02/11/24.
//

#ifndef Heun_Method_hpp
#define Heun_Method_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "Constant.h"
#include "Polynomial.hpp"
//#include "gnuplot-iostream.h"

double poly2(double x, double t, int n, int m, const std::vector<vector<double>>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d, vector<double> xp, vector<double> tp);

int Heun();

#endif /* Heun_Method_hpp */
