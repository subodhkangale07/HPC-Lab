#include <stdio.h>
#include <omp.h>

int main() {
    int size = 100000;           
    int scalar = 5;              
    int a[size], b[size];        

    for (int i = 0; i < size; i++) {
        a[i] = i;
    }

    double start = omp_get_wtime();

    // Add scalar to each element using OpenMP
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        b[i] = a[i] + scalar;
    }

    double end = omp_get_wtime();

    printf("First 5 results:\n");
    for (int i = 0; i < 5; i++) {
        printf("b[%d] = %d\n", i, b[i]);
    }

    printf("Time taken: %f seconds\n", end - start);

    return 0;
}
