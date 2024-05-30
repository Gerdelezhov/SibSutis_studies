#include <iostream>
#include <thread>
#include <vector>
#include <numeric>
#include <chrono>

// Функция, которую будут выполнять потоки
void sumRange(const std::vector<int>& numbers, size_t start, size_t end, int& result) {
    result = std::accumulate(numbers.begin() + start, numbers.begin() + end, 0);
}

int main() {
    std::vector<int> numbers(1000001);
    std::iota(numbers.begin(), numbers.end(), 0); // Заполняем вектор числами от 0 до 1000
    int numThreads = 4; // Количество потоков

    std::vector<std::thread> threads(numThreads);
    std::vector<int> partialSums(numThreads);

    size_t chunkSize = numbers.size() / numThreads;

    auto start = std::chrono::high_resolution_clock::now();

    // Создаем и запускаем потоки
    for (int i = 0; i < numThreads; i++) {
        size_t start = i * chunkSize;
        size_t end = (i == numThreads - 1) ? numbers.size() : (start + chunkSize);
        threads[i] = std::thread(sumRange, std::ref(numbers), start, end, std::ref(partialSums[i]));
    }

    // Ждем завершения всех потоков
    for (int i = 0; i < numThreads; i++) {
        threads[i].join();
    }

    // Суммируем частичные суммы
    int totalSum = std::accumulate(partialSums.begin(), partialSums.end(), 0);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Сумма: " << totalSum << std::endl;
    std::cout << "Время выполнения: " << duration.count() << " секунд" << std::endl;

    return 0;
}
