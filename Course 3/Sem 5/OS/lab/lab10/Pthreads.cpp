#include <iostream>
#include <vector>
#include <pthread.h>
#include <numeric>
#include <chrono>
#include <mutex>

struct ThreadArgs {
    const std::vector<int>* numbers;
    size_t start;
    size_t end;
    long long result;
};

const int numThreads = 4;
std::vector<pthread_t> threads(numThreads);
std::vector<ThreadArgs> threadArgs(numThreads);

std::mutex mtx;

void sumRange(ThreadArgs* args) {
    args->result = std::accumulate(args->numbers->begin() + args->start, args->numbers->begin() + args->end, 0LL);
}

void* threadFunc(void* args) {
    ThreadArgs* threadArgs = static_cast<ThreadArgs*>(args);

    sumRange(threadArgs);

    return nullptr;
}

int main() {
    std::vector<int> numbers(1000001);
    std::iota(numbers.begin(), numbers.end(), 0);
    
    size_t chunkSize = numbers.size() / numThreads;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numThreads; i++) {
        size_t startRange = i * chunkSize;
        size_t endRange = (i == numThreads - 1) ? numbers.size() : (i + 1) * chunkSize;

        threadArgs[i] = {&numbers, startRange, endRange, 0LL};
        pthread_create(&threads[i], nullptr, threadFunc, &threadArgs[i]);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], nullptr);
        std::cout << "Часть суммы от " << threadArgs[i].start << " до " << threadArgs[i].end << ": " << threadArgs[i].result << std::endl;
    }

    long long totalSum = 0LL;
    for (int i = 0; i < numThreads; i++) {
        totalSum += threadArgs[i].result;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Общая сумма: " << totalSum << std::endl;
    std::cout << "Время выполнения: " << duration.count() << " секунд" << std::endl;

    return 0;
}
