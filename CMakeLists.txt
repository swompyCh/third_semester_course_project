cmake_minimum_required(VERSION 3.15)
project(FactorialBenchmark)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем FetchContent для загрузки зависимостей
include(FetchContent)

# Настраиваем FetchContent для Google Benchmark
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.8.0 # Указываем стабильную версию библиотеки
)
# Отключаем тесты Benchmark для упрощения сборки
set(BENCHMARK_ENABLE_TESTING OFF)
FetchContent_MakeAvailable(benchmark)

# Указываем основной исходный файл
add_executable(FactorialBenchmark main.cpp)

# Линкуем библиотеку Google Benchmark и pthread
target_link_libraries(FactorialBenchmark PRIVATE benchmark::benchmark pthread)

# Устанавливаем режим сборки Release по умолчанию
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()
