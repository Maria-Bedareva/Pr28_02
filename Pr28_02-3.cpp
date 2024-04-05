#include <iostream>
#include <omp.h>

int main() {
    int num_threads;
    std::cout << "Enter the number of threads: ";
    std::cin >> num_threads;

#pragma omp parallel num_threads(num_threads)
    {
        int thread_num = omp_get_thread_num();
#pragma omp critical
        {
            std::cout << "Thread " << thread_num << std::endl;
        }
    }

    return 0;
}



