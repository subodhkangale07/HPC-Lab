#include <stdio.h>
#include <omp.h>

#define SIZE 200

int main() {
    int i;
    float a[SIZE], result[SIZE];
    float scalar = 2.5;

    for (i = 0; i < SIZE; i++)
        a[i] = i * 1.0;

    printf("Static schedule (chunk=10):\n");
    #pragma omp parallel for schedule(static, 10)
    for (i = 0; i < SIZE; i++) {
        result[i] = a[i] + scalar;
    }

    printf("Dynamic schedule (chunk=5):\n");
    #pragma omp parallel for schedule(dynamic, 5)
    for (i = 0; i < SIZE; i++) {
        result[i] = a[i] + scalar;
    }

    printf("Using nowait clause:\n");
    #pragma omp parallel
    {
        #pragma omp for nowait
        for (i = 0; i < SIZE; i++)
            result[i] = a[i] + scalar;

        #pragma omp single
        printf("No wait after for-loop. Continuing...\n");
    }

    printf("Ordered output of first 10 elements:\n");
    #pragma omp parallel for ordered schedule(static)
    for (i = 0; i < 10; i++) {
        #pragma omp ordered
        printf("result[%d] = %.2f\n", i, result[i]);
    }

    return 0;
}
