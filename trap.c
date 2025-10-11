#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Trap(double a, double b, int n, double* global_result_p);

int main(int argc, char* argv[]) {
    double global_result = 0.0;
    double a, b;
    int n;
    int thread_count;

    thread_count = strtol(argv[1], NULL, 10);
    printf("Enter a, b, and n\n");
    scanf("%lf %lf %d", &a, &b, &n);

    #pragma omp parallel num_threads(thread_count)
    Trap(a, b, n, &global_result);

    printf("With n = %d trapezoids, our estimate\n", n);
    printf("of the integral from %f to %f = %.14e\n", a, b, global_result);
    return 0;
}

void Trap(double a, double b, int n, double* global_result_p) {
    double h, x, my_result;
    double local_a, local_b;
    int i, local_n;
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    h = (b - a) / n;
    local_n = n / thread_count;
    local_a = a + my_rank * local_n * h;
    local_b = local_a + local_n * h;

    my_result = (f(local_a) + f(local_b)) / 2.0;
    for (i = 1; i <= local_n - 1; i++) {
        x = local_a + i * h;
        my_result += f(x);
    }

    my_result = my_result * h;

    #pragma omp critical
    *global_result_p += my_result;
}
#include <stdio.h> 
#include <omp.h> 
 
int main() 
{ 
int prime[1000], i, j, n; 
 
// Prompt user for input 
printf("\n In order to find prime numbers from 1 to n, enter the value of n:"); 
scanf("%d", &n); 
 
// Initialize all numbers as prime (set all to 1) 
for(i = 1; i <= n; i++) { 
prime[i] = 1; 
 } 
// 1 is not a prime number 
prime[1] = 0; 
// Sieve of Eratosthenes with parallelization 
for(i = 2; i * i <= n; i++) { 
#pragma omp parallel for 
for(j = i * i; j <= n; j = j + i) { 
if(prime[j] == 1) { 
prime[j] = 0; 
} 
} 
} 
// Print prime numbers 
printf("\n Prime numbers from 1 to %d are\n", n); 
for(i = 2; i <= n; i++) { 
if(prime[i] == 1) { 
printf("%d\t", i); 
} 
} 
double start, end; 
// Sequential  
start = omp_get_wtime(); 
prime[i]; 
end = omp_get_wtime(); 
printf("Sequential Time: %f seconds\n",end-start); 
// Parallel 
start = omp_get_wtime(); 
prime[i]; 
end = omp_get_wtime(); 
printf("Parallel Time: %f seconds\n",end-start); 
printf("\n"); 
}