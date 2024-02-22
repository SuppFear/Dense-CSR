#include "dense_matrix.h"

Dense_Matrix::Dense_Matrix(const std::size_t &n, const std::vector<double> &matrixElements) : n(n), matrixElements(matrixElements) {}

const double Dense_Matrix::operator()(std::size_t i, std::size_t j) const {
    return this->matrixElements[i * this->n + j];
}

const Dense_Matrix Dense_Matrix::operator*(const double &x) const{
    std::vector<double> matrixElements_new = std::vector<double>(this->matrixElements.size());
    for (unsigned int i = 0; i < this->matrixElements.size(); i++){
        matrixElements_new[i] = x * this->matrixElements[i];
    }
    Dense_Matrix result = {n, matrixElements_new};
    return result;
}

const Dense_Matrix operator*(const double &x, const Dense_Matrix &A){
    return A*x;
}

const std::vector<double> Dense_Matrix::operator*(const std::vector<double> &v) const{
    std::size_t r = this->matrixElements.size() / this->n;
    //std::cout<<r;
    std::vector<double> result = std::vector<double>(r);
    for (unsigned int i = 0; i < r; i++){
        result[i] = 0;
        for (size_t j = i * this->n; j < i * this->n + this->n; j++){
            //std::cout<<j;
            result[i] += this->matrixElements[j] * v[j%n];
            //std::cout<<result[i];
        }
    }
    return result;
}

const std::vector<double> Dense_Matrix::get_matrixElemenets() const {
    return this->matrixElements;
}

const std::size_t Dense_Matrix::columns() const {
    return this->n;
}

// int main(){
//     std::vector<double> v = {1., 2., 0., 3., 0., 4., 0., 2., 0., 4., 6., 2.};
//     Dense_Matrix a{4, v};
//     //std::cout<<a(1, 1);
//     Dense_Matrix aa = 2*a;
//     //std::cout<<aa(1, 1);
//     std::vector<double> vec = {3., 2., 2., 1.};
//     std::vector<double> res = a*vec;
//     std::cout<<res[0]<< res[1]<< res[2];
// }