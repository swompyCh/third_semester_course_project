#include <benchmark/benchmark.h>

// Рекурсивная функция вычисления факториала
unsigned long long factorial_recursive(unsigned long long n) {
    if (n <= 1) return 1;
    return n * factorial_recursive(n - 1);
}

// Итеративная функция вычисления факториала
unsigned long long factorial_iterative(unsigned long long n) {
    unsigned long long result = 1;
    for (unsigned long long i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Бенчмарк для рекурсивного метода
static void BM_FactorialRecursive(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(factorial_recursive(state.range(0)));
    }
}
BENCHMARK(BM_FactorialRecursive)->Arg(100)->Arg(150)->Arg(200);

// Бенчмарк для итеративного метода
static void BM_FactorialIterative(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(factorial_iterative(state.range(0)));
    }
}
BENCHMARK(BM_FactorialIterative)->Arg(100)->Arg(150)->Arg(200);

BENCHMARK_MAIN();
