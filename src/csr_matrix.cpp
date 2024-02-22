#include "csr_matrix.h"
//#include "dense_matrix.h"

CSR_Matrix::CSR_Matrix(const std::vector<double> &values, const std::vector<std::size_t> &cols, const std::vector<std::size_t> &rows) : values(values), cols(cols), rows(rows) {}
// CSR_Matrix::CSR_Matrix(const Dense_Matrix &a){
//     std::vector<double> elems = a.get_matrixElemenets();
//     std::size_t n = a.columns();
//     this->rows.push_back(0);
//     unsigned int sum = 0;
//     for (unsigned int i = 0; i < elems.size(); i++){
//         if (elems[i] != 0){
//             this->values.push_back(elems[i]);
//             this->cols.push_back(i % n);
//             sum++;
//         }
//         if (i % n == 0 && i != 0){
//             this->rows.push_back(sum);
//             sum = 0;
//         }
//     }
// }


const double CSR_Matrix::operator()(std::size_t i, std::size_t j) const{
    for(std::size_t k = this->rows[i]; k < this->rows[i+1]; k++){
        if (cols[k] == j){
            return this->values[k];
        }
    }
    return 0;
}

const CSR_Matrix CSR_Matrix::operator*(const double &n) const{
    std::vector<double> values_new = std::vector<double>(this->values.size());
    for (unsigned int i = 0; i < this->values.size(); i++){
        values_new[i] = n*this->values[i];
    }
    CSR_Matrix result{values_new, cols, rows};
    return result;
}

const CSR_Matrix operator*(const double &n, const CSR_Matrix &A){
    return A*n;
}

const std::vector<double> CSR_Matrix::operator*(const std::vector<double> &v) const{
    std::vector<double> result = std::vector<double>(this->rows.size() - 1);
    for (unsigned int i = 1; i < this->rows.size(); i++){
        result[i-1] = 0;
        for (unsigned int j = this->rows[i-1]; j < this->rows[i]; j++){
            result[i-1] += this->values[j] * v[this->cols[j]];
        }
    }
    return result;
}

// int main(){
//     std::vector<double> v = {1., 2., 4., 4., 6.};
//     std::vector<std::size_t> c = {0, 1, 1, 1, 2};
//     std::vector<std::size_t> r = {0, 2, 3, 5};
//     CSR_Matrix a{v, c, r};
//     CSR_Matrix b = 2*a;
//     std::cout<<b.values[2];
//     //std::cout<<a.values[0];
//     std::vector<double> vec = {3., 2., 2.};
//     std::vector<double> res = a*vec;
//     std::cout<<res[0]<< res[1]<< res[2];
// }