#include <iostream>
#include <omp.h>

int main() {
    int num_times = 5;

#pragma omp parallel for
    for (int i = 0; i < num_times; ++i) {
        std::cout << "Hello World!" << std::endl;
    }

    return 0;
}
