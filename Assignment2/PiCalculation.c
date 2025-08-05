#include <stdio.h>
#include <omp.h>

int main() {
    long steps = 100000000;    
    double step = 1.0 / steps;
    double sum = 0.0;

    double start = omp_get_wtime();

    // Calculate Pi using parallel loop
    #pragma omp parallel for reduction(+:sum)
    for (long i = 0; i < steps; i++) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    double pi = step * sum;

    double end = omp_get_wtime();

    printf("Estimated value of Pi = %.15f\n", pi);
    printf("Time taken: %f seconds\n", end - start);

    return 0;
}
