#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the position: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative number." << endl;
        return 0;
    }

    int fib[100];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << "Fibonacci number: " << fib[n] << endl;

    return 0;
}
