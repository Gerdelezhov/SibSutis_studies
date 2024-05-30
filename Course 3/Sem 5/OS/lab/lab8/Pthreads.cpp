#include <iostream>
#include <vector>
#include <pthread.h>
#include <numeric>
#include <chrono>

// Структура для передачи аргументов в поток
struct ThreadArgs {
    const std::vector<int>& numbers;
    size_t start;
    size_t end;
    int result;
};

// Функция, которую будут выполнять потоки
void* sumRange(void* args) {
    ThreadArgs* threadArgs = static_cast<ThreadArgs*>(args);
    threadArgs->result = std::accumulate(threadArgs->numbers.begin() + threadArgs->start, threadArgs->numbers.begin() + threadArgs->end, 0);
    return nullptr;
}

int main() {
    std::vector<int> numbers(1000001);
    std::iota(numbers.begin(), numbers.end(), 0); // Заполняем вектор числами от 0 до 1000
    int numThreads = 4; // Количество потоков

    std::vector<pthread_t> threads(numThreads);
    std::vector<ThreadArgs*> threadArgs(numThreads);

    size_t chunkSize = numbers.size() / numThreads;

    auto start = std::chrono::high_resolution_clock::now();

    // Создаем и запускаем потоки
    for (int i = 0; i < numThreads; i++) {
        threadArgs[i] = new ThreadArgs{numbers, i * chunkSize, (i == numThreads - 1) ? numbers.size() : (i + 1) * chunkSize, 0};
        pthread_create(&threads[i], nullptr, sumRange, threadArgs[i]);
    }

    // Ждем завершения всех потоков
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], nullptr);
    }

    // Суммируем частичные суммы
    int totalSum = 0;
    for (int i = 0; i < numThreads; i++) {
        totalSum += threadArgs[i]->result;
        delete threadArgs[i]; // Освобождаем выделенную память
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Сумма: " << totalSum << std::endl;
    std::cout << "Время выполнения: " << duration.count() << " секунд" << std::endl;

    return 0;
}
