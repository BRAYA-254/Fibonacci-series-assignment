#include <iostream>
using namespace std;

int fibonacci(int n, int memo[]) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1, memo)
            + fibonacci(n - 2, memo);

    return memo[n];
}

int main() {
    int n;

    cout << "Enter the position: ";
    cin >> n;

    if (n < 0 || n >= 100) {
        cout << "Enter a number from 0 to 99." << endl;
        return 0;
    }

    int memo[100];

    for (int i = 0; i < 100; i++) {
        memo[i] = -1;
    }

    cout << "Fibonacci number: "
         << fibonacci(n, memo) << endl;

    return 0;
}
