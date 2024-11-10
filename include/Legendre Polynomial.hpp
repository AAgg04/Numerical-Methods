//
//  Legendre Polynomial.hpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 07/11/24.
//

#ifndef Legendre_Polynomial_hpp
#define Legendre_Polynomial_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

#include "Constant.h"

double factorial(int n);

double Leg(double x, int n);

double Leg1(double x, int n);

std::vector<double> Rhap(int n);

std::vector<double> weight(const std::vector<double>& root, int n);

#endif /* Legendre_Polynomial_hpp */
