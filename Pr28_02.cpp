#include <iostream>
#include <omp.h>

int main() {
    setlocale(LC_ALL, "Russian");
    int k, N;
    std::cout << "Введите количество потоков: ";
    std::cin >> k;
    std::cout << "Введите количество чисел: ";
    std::cin >> N;

    int total_sum = 0;

#pragma omp parallel num_threads(k) reduction(+:total_sum)
    {
        int thread_num = omp_get_thread_num();
        int sum = 0;

        int chunk_size = N / k;
        int start = 1 + thread_num * chunk_size;
        int end = start + chunk_size - 1;

        if (thread_num == k - 1) {
            end = N;
        }

        for (int i = start; i <= end; ++i) {
            sum += i;
        }

#pragma omp critical
        {
            std::cout << "[" << thread_num << "]: Сумма = " << sum << std::endl;
        }

#pragma omp barrier // Барьер для ожидания всех потоков

#pragma omp master
        {
            std::cout << "Все потоки завершили вычисления." << std::endl;
        }

        total_sum += sum;
    }

    std::cout << "Сумма = " << total_sum << std::endl;

    return 0;
}
