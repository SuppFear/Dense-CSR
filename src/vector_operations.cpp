#include "vector_operations.h"

const std::vector<double> operator*(const double &x, const std::vector<double> &v){
    std::vector<double> result = std::vector<double>(v.size());
    for (unsigned int i = 0; i < v.size(); i++){
        result[i] = x * v[i];
    }
    return result;
}

const std::vector<double> operator*(const std::vector<double> &v, const double &x){
    return x*v;
}

const double operator*(const std::vector<double> &v, const std::vector<double> &vv){
    double result = 0;
    for (unsigned int i = 0; i < v.size(); i++){
        result += v[i] * vv[i];
    }
    return result;
}

const std::vector<double> operator+(const std::vector<double> &v, const std::vector<double> &vv){
    std::vector<double> result = std::vector<double>(v.size());
    for (unsigned int i = 0; i < v.size(); i++){
        result[i] = v[i] + vv[i];
    }
    return result;
}

const std::vector<double> operator-(const std::vector<double> &v, const std::vector<double> &vv){
    std::vector<double> result = std::vector<double>(v.size());
    for (unsigned int i = 0; i < v.size(); i++){
        result[i] = v[i] - vv[i];
    }
    return result;
}

int main(){
    std::vector<double> v = {1., 2., 3., 4.};
    std::vector<double> vv = 2*v;
    //std::cout<<vv[2];
    //std::cout<<v*vv;
    std::vector<double> vvv = vv - v;
    std::cout<<vvv[2];
}