//
//  Polynomial.hpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 25/10/24.
//

#ifndef Polynomial_hpp
#define Polynomial_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <functional>

#include "Matrix Operations.hpp"
#include "exprtk.hpp"

using functions = std::function<double(double)>;

extern std::unordered_map<std::string, std::function<double(double)>> funcMap;

double poly(double x, int n, int m, const std::vector<double>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d);

double poly2(double x, double t, int n, int m, const std::vector<vector<double>>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d, vector<double> xp, vector<double> tp);

double polyn(const std::vector<double>& x, int v, int n, int m, const std::vector<vector<vector<double>>>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d);

#endif /* Polynomial_hpp */
