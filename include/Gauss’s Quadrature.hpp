//
//  Gauss’s Quadrature.hpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 07/11/24.
//

#ifndef Gauss_s_Quadrature_hpp
#define Gauss_s_Quadrature_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>

#include "Constant.h"
#include "Polynomial.hpp"
#include "Legendre Polynomial.hpp"

double poly(double x, int n, int m, const std::vector<double>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d);

double factorial(int n);

double Leg(double x, int n);

double Leg1(double x, int n);

std::vector<double> Rhap(int n);

std::vector<double> weight(const std::vector<double>& root, int n);

int GQ();

#endif /* Gauss_s_Quadrature_hpp */
