#include <iostream>
#include <vector>

class Dense_Matrix{
private:
    std::size_t n; // number of columns
    std::vector<double> matrixElements;
public:
    Dense_Matrix(const std::size_t &n, const std::vector<double> &matrixElements);
    const double operator()(std::size_t i, std::size_t j) const;
    const std::vector<double> operator*(const std::vector<double> &v) const;
    const Dense_Matrix operator*(const double &x) const;
    const std::size_t columns() const;
    const std::vector<double> get_matrixElemenets() const;
};