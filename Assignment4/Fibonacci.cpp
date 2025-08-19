#include <iostream>
#include <omp.h>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 10;
    int result[10];

    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        int value = fib(i);

        #pragma omp critical
        {
            result[i] = value;
        }
    }

    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
