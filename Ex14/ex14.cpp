#include <chrono>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>
#include <thread>
#include <mutex>

std::mutex resultMutex;

// Complete: Additional necessary headers ...

// Complete: write the function split that computes the lower/higher indices
// for which each thread will be responsible.
void split(std::size_t nele, std::size_t nthreads,
           std::vector<std::size_t> &lower, std::vector<std::size_t> &upper)
{
    std::size_t partSize = nele / nthreads;
    std::size_t remaining = nele % nthreads;

    std::size_t start = 0;
    std::size_t end = 0;

    for (std::size_t i = 0; i < nthreads; ++i)
    {
        lower.push_back(start);
        end = start + partSize + (remaining > 0 ? 1 : 0);
        upper.push_back(end);
        start = end;
        if (remaining > 0)
        {
            remaining--;
        }
    }
}

// Complete: add dot_product and modify it such that there is no race condition.
void dot_product(const std::vector<double> &v1, const std::vector<double> &v2,
                 std::size_t lower, std::size_t higher, double *result)
{
    double sum = 0;
    for (std::size_t i = lower; i < higher; ++i)
    {
        sum += v1[i] * v2[i];
    }

    *result += sum;
}

// Complete: the parallel_dot_product function that computes on nthreads the dot product
// of v1 and v2
double parallel_dot_product(const std::vector<double> &v1, const std::vector<double> &v2,
                            std::size_t nthreads)
{

    if (v1.size() != v2.size())
        throw std::runtime_error("Sizes of v1 and v2 don't match");

    std::size_t nele = v1.size();
    double result = 0;

    // Split 'nele' elements into 'nthreads' part
    std::vector<std::size_t> lower;
    std::vector<std::size_t> higher;
    // lower[i] and higher[i] contains the lower and higher indices
    // for which a given thread will compute the dot product
    split(nele, nthreads, lower, higher);

    // Complete: start 'nthreads' threads
    // don't forget to pass explicitly a reference to the arrays v1 and v2
    std::vector<std::thread> threads;
    for (std::size_t i = 0; i < nthreads; ++i)
    {
        // start a thread that will compute the dot product between v1 and v2
        // for indices between lower[i] and higher[i]
        threads.emplace_back([&v1, &v2, &lower, &higher, i, &result]()
                             {
            dot_product(v1, v2, lower[i], higher[i], &result);
            std::lock_guard<std::mutex> lock(resultMutex); });
    }

    // Complete: join the threads with the main thread
    for (auto &thread : threads)
    {
        thread.join();
    }

    return result;
}

void usage(const char *pname)
{
    std::cout << "Incorrect number of arguments" << std::endl;
    std::cout << "Usage: " << pname << " nele nthreads" << std::endl;
    std::cout << "where nele is the number of elements in the random vectors" << std::endl;
    std::cout << "and nthreads is the number of threads to be used" << std::endl;
    exit(1);
}

int main(int argc, char **argv)
{
    if (argc != 3)
        usage(argv[0]);

    std::size_t nele = std::stoi(argv[1]);
    std::size_t nthreads = std::stoi(argv[2]);

    std::vector<double> v1(nele);

    // complete: fill v1 with random integers
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0, 10);

    for (int i = 0; i < int(v1.size()); ++i)
    {
        v1[i] = dis(gen);
    }

    for (size_t i = 0; i < nele; ++i)
    {
        v1[i] = double(rand()) / double(RAND_MAX);
    }

    std::vector<double> v2(nele);
    for (size_t i = 0; i < nele; ++i)
    {
        v2[i] = double(rand()) / double(RAND_MAX);
    }

    // multi-threaded version
    std::cout << "multi-threaded version" << std::endl;
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    double result = parallel_dot_product(v1, v2, nthreads);
    std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();

    std::cout << "Result: " << result << " / Elapsed time (ms): "
              << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count()
              << std::endl;

    // normal version
    std::cout << "normal version" << std::endl;

    result = 0;
    start = std::chrono::steady_clock::now();
    dot_product(v1, v2, 0, nele, &result);
    stop = std::chrono::steady_clock::now();

    std::cout << "Result: " << result << " / Elapsed time (ms): "
              << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count()
              << std::endl;
}