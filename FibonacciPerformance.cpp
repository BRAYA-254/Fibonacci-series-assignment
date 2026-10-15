#include <iostream>
#include <ctime>
using namespace std;

// 1. Recursive approach
long long recursiveFib(int n) {
    if (n <= 1)
        return n;

    return recursiveFib(n - 1) + recursiveFib(n - 2);
}

// 2. Iterative approach
long long iterativeFib(int n) {
    if (n <= 1)
        return n;

    long long fib[31];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

// 3. Dynamic programming using memoization
long long memoFib(int n, long long memo[]) {
    if (n <= 1)
        return n;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = memoFib(n - 1, memo)
            + memoFib(n - 2, memo);

    return memo[n];
}

int main() {
    int n = 30;
    long long result;
    clock_t start, stop;

    // Recursive timing
    start = clock();
    result = recursiveFib(n);
    stop = clock();

    cout << "Recursive result: " << result << endl;
    cout << "Recursive time: "
         << 1000000.0 * (stop - start) / CLOCKS_PER_SEC
         << " microseconds\n\n";

    // Iterative timing
    start = clock();
    result = iterativeFib(n);
    stop = clock();

    cout << "Iterative result: " << result << endl;
    cout << "Iterative time: "
         << 1000000.0 * (stop - start) / CLOCKS_PER_SEC
         << " microseconds\n\n";

    // Memoization timing
    long long memo[31];

    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    start = clock();
    result = memoFib(n, memo);
    stop = clock();

    cout << "Memoization result: " << result << endl;
    cout << "Memoization time: "
         << 1000000.0 * (stop - start) / CLOCKS_PER_SEC
         << " microseconds\n";

    return 0;
}
