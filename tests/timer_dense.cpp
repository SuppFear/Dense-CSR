#include "dense_matrix.h"
#include <fstream>
#include <time.h>
#include <chrono>
#include <random>

int main(){
    std::ofstream out;
    out.open("dense3.txt");
    if (out.is_open())
    {
        for (unsigned int n = 100; n <= 1000; n += 100){
            std::vector<double> v(n*n, 0.0);
            std::vector<double> b = std::vector<double>(n);
            std::iota(b.begin(), b.end(), 1);
            for (unsigned int i = 0; i < n*n; i+=20){
                srand(time(NULL));
                v[i] = 1 + rand() % n*n;
            }
            Dense_Matrix a{n, v};
            std::cout << n << std::endl;
            auto start = std::chrono::high_resolution_clock::now();
            auto c = a*b;
            auto end = std::chrono::high_resolution_clock::now();
            out << std::to_string(n) << " " << std::to_string((end-start).count()) << std::endl; 
        }   
    }
    out.close(); 
}