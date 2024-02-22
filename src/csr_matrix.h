#include <iostream>
#include <vector>
#include "dense_matrix.h"

class CSR_Matrix{
private:
    std::vector<double> values;
    std::vector<std::size_t> cols;
    std::vector<std::size_t> rows;
public:
    CSR_Matrix(const std::vector<double> &values, const std::vector<std::size_t> &cols, const std::vector<std::size_t> &rows);
    CSR_Matrix(const Dense_Matrix &a);
    const double operator()(std::size_t i, std::size_t j) const;
    const std::vector<double> operator*(const std::vector<double> &v) const;
    const CSR_Matrix operator*(const double &n) const;
};