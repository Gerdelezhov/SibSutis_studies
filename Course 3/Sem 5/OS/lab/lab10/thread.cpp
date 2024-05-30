#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <chrono>
#include <mutex>

void sumRange(const std::vector<int>& numbers, size_t start, size_t end, long long int& result, std::mutex& mtx) {
    long long int partialSum = std::accumulate(numbers.begin() + start, numbers.begin() + end, 0LL); // Используем 0LL для явного указания на тип long long int
    mtx.lock();
    std::cout << "Часть суммы от " << start << " до " << end << ": " << partialSum << std::endl;
    mtx.unlock();

    result = partialSum;
}

int main() {
    std::vector<int> numbers(1000001);
    std::iota(numbers.begin(), numbers.end(), 0);
    int numThreads = 4;

    std::vector<std::thread> threads(numThreads);
    std::vector<long long int> partialSums(numThreads); // Изменяем тип данных для частичных сумм
    std::mutex mtx;

    size_t chunkSize = numbers.size() / numThreads;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numThreads; i++) {
        size_t start = i * chunkSize;
        size_t end = (i == numThreads - 1) ? numbers.size() : (start + chunkSize);
        threads[i] = std::thread(sumRange, std::ref(numbers), start, end, std::ref(partialSums[i]), std::ref(mtx));
    }

    for (int i = 0; i < numThreads; i++) {
        threads[i].join();
    }

    long long int totalSum = std::accumulate(partialSums.begin(), partialSums.end(), 0LL); // Используем 0LL для явного указания на тип long long int

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Общая сумма: " << totalSum << std::endl;
    std::cout << "Время выполнения: " << duration.count() << " секунд" << std::endl;

    return 0;
}
