//
//  Polynomial.cpp
//  Numerical Methods
//
//  Created by Amogh Aggarwal on 25/10/24.
//

#include "Polynomial.hpp"

using namespace std;

std::unordered_map<std::string, function<double(double)>> funcMap = {
    {"cos", [](double val) { return cos(val); }},
    {"sin", [](double val) { return sin(val); }},
    {"tan", [](double val) { return tan(val); }},
    {"acos", [](double val) { return acos(val); }},
    {"asin", [](double val) { return asin(val); }},
    {"atan", [](double val) { return atan(val); }},
    {"cosh", [](double val) { return cosh(val); }},
    {"sinh", [](double val) { return sinh(val); }},
    {"tanh", [](double val) { return tanh(val); }},
    {"log", [](double val) { return log(val); }},
    {"exp", [](double val) { return exp(val); }},
    {"sqrt", [](double val) { return sqrt(val); }},
    {"fabs", [](double val) { return fabs(val); }},
    {"log10", [](double val) { return log10(val); }},
    {"log2", [](double val) { return log2(val); }},
    {"square", [](double val) { return val * val; }},
    {"cube", [](double val) { return val * val * val; }},
    {"sec", [](double val) { return 1 / cos(val); }},
    {"csc", [](double val) { return 1 / sin(val); }},
    {"cot", [](double val) { return 1 / tan(val); }},
    {"sech", [](double val) { return 1 / cosh(val); }},
    {"csch", [](double val) { return 1 / sinh(val); }},
    {"coth", [](double val) { return 1 / tanh(val); }},
    {"tgamma", [](double val) { return tgamma(val); }},
    {"erf", [](double val) { return erf(val); }},
    {"erfc", [](double val) { return erfc(val); }}
};

double poly(double x, int n, int m, const std::vector<double>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d) {
    
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += a[i] * pow(x, i);
    }
    
    for (int i = 0; i < m; i++) {
            if (b[i] == "pow") {
                sum += pow(c[i], d[i] * x);
            } else if (funcMap.find(b[i]) != funcMap.end()) {
                sum += c[i] * funcMap[b[i]](d[i] * x);
            } else {
                cout << "Invalid function name: " << b[i] << endl;
            }
        }
    
    return sum;
}


double poly2(double x, double t, int n, int m, const std::vector<vector<double>>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d, vector<double> xp, vector<double> tp) {
    
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            sum += a[i][j] * pow(x, i) * pow(t, j);
        }
    }
    
    for (int i = 0; i < m; i++) {
            if (b[i] == "pow") {
                sum += pow(c[i], d[i] * pow(x, xp[i]) * pow(t, tp[i]));
            } else if (funcMap.find(b[i]) != funcMap.end()) {
                sum += c[i] * funcMap[b[i]](d[i] * pow(x, xp[i]) * pow(t, tp[i]));
            } else {
                cout << "Invalid function name: " << b[i] << endl;
            }
        }
    
    return sum;
}

double polyn(const std::vector<double>& x, int v, int n, int m, const std::vector<std::vector<std::vector<double>>>& a, const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d) {
    
    double sum = 0;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            double term = 0;
            for (int degree = 0; degree <= n; degree++) {
                double partial_term = a[i][j][degree] * pow(x[i], degree) * pow(x[j], degree);
                term += partial_term;

            }
            sum += term;

            // Handling additional functions with funcMap or exprtk (if any exist)
            for (int k = 0; k < m; k++) {
                if (funcMap.find(b[k]) != funcMap.end()) {
                    sum += c[k] * funcMap[b[k]](d[k] * term);
                } else {
                    double term_copy = term;
                    double d_copy = d[k];
                    
                    exprtk::symbol_table<double> symbol_table;
                    symbol_table.add_variable("term", term_copy);
                    symbol_table.add_variable("d", d_copy);
                    symbol_table.add_constants();

                    exprtk::expression<double> expression;
                    expression.register_symbol_table(symbol_table);

                    exprtk::parser<double> parser;

                    if (!parser.compile(b[k], expression)) {
                        std::cout << "Error in expression '" << b[k] << "': " << parser.error() << std::endl;
                        continue;
                    }

                    double expr_result = expression.value();
                    sum += c[k] * expr_result;

                }
            }
        }
    }

    return sum;
}

//double polyn(const std::vector<double>& x, int v, int n, int m, const std::vector<std::vector<double>>& a,
//             const std::vector<std::string>& b, const std::vector<double>& c, const std::vector<double>& d) {
//
//    double sum = 0;
//
//        // Step 1: Calculate polynomial terms
//        for (int i = 0; i < v; i++) {
//            for (int degree = 0; degree <= n; degree++) {
//                double term = a[i][degree] * pow(x[i], degree);
//                sum += term;
//            }
//        }
//
//        // Step 2: Evaluate additional non-linear functions
//        for (int k = 0; k < m; k++) {
//            double functionResult = 0.0;
//
//            if (funcMap.find(b[k]) != funcMap.end()) {
//                // Use predefined non-linear function from funcMap
//                functionResult = funcMap[b[k]](d[k] * x[0]); // Example using x[0]; adjust as needed
//            } else {
//                // Use exprtk to parse and evaluate custom non-linear expression
//                exprtk::symbol_table<double> symbol_table;
//                double x0_copy = x[0]; // Adjust if multiple variables need to be considered
//                symbol_table.add_variable("x0", x0_copy); // Example variable x[0]
//                symbol_table.add_constants();
//
//                exprtk::expression<double> expression;
//                expression.register_symbol_table(symbol_table);
//
//                exprtk::parser<double> parser;
//
//                if (!parser.compile(b[k], expression)) {
//                    std::cerr << "Error in expression '" << b[k] << "': " << parser.error() << std::endl;
//                    continue;
//                }
//
//                functionResult = expression.value();
//            }
//
//            // Multiply by coefficient c[k] and add to sum
//            sum += c[k] * functionResult;
//        }
//
//        return sum;
//    }
//
