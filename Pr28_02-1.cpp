#include <iostream>
#include <omp.h>

int main() {
    // Указываем количество раз, которое нужно вывести приветствие
    int num_times = 5;

    // Директива OpenMP для создания параллельного цикла
#pragma omp parallel for
    for (int i = 0; i < num_times; ++i) {
        std::cout << "Hello World!" << std::endl;
    }

    return 0;
}
