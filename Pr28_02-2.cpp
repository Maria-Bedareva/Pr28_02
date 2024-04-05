#include <iostream>
#include <omp.h>

int main() {
    int n;
    std::cout << "Enter the number of threads: ";
    std::cin >> n;
#pragma omp parallel for
    for (int i = 0; i < n; i++) {
#pragma omp critical
        {
            std::cout << "Thread " << omp_get_thread_num() << " is executing iteration " << n << std::endl;
        }
    }

    return 0;
}


