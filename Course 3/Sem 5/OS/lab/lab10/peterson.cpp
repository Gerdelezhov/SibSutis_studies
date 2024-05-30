#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>

std::atomic<bool> want[2] = {false, false};
std::atomic<int> turn = 0;

void enter_critical_section(int process_number) {
    int other_process = 1 - process_number;
    want[process_number].store(true, std::memory_order_relaxed);
    turn.store(other_process, std::memory_order_relaxed);
    while (want[other_process].load(std::memory_order_relaxed) && turn.load(std::memory_order_relaxed) == other_process) {
        // ждем, пока другой процесс не завершит критическую секцию
    }
    // вход в критическую секцию
    std::cout << "Процесс " << process_number << " вошел в критическую секцию." << std::endl;
}

void exit_critical_section(int process_number) {
    want[process_number].store(false, std::memory_order_relaxed);
    // выход из критической секции
    std::cout << "Процесс " << process_number << " вышел из критической секции." << std::endl;
}

void test_algorithm() {
    std::thread t1([&]() {
        enter_critical_section(0);
        // критическая секция для процесса 0
        std::this_thread::sleep_for(std::chrono::seconds(1));
        exit_critical_section(0);
    });

    std::thread t2([&]() {
        enter_critical_section(1);
        // критическая секция для процесса 1
        exit_critical_section(1);
    });

    t1.join();
    t2.join();
}

int main() {
    test_algorithm();
    return 0;
}
