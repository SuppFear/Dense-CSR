#include <iostream>
#include <vector>

const std::vector<double> operator*(const double &x, const std::vector<double> &v);
const std::vector<double> operator*(const std::vector<double> &v, const double &x);
const double operator*(const std::vector<double> &v, const std::vector<double> &vv);
const std::vector<double> operator+(const std::vector<double> &v, const std::vector<double> &vv);
const std::vector<double> operator-(const std::vector<double> &v, const std::vector<double> &vv);