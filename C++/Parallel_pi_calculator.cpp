#include <omp.h>
#include <iostream>

using namespace std;

#define NUM_THREADS 8

static long num_trials = 3000000000;

int main(int argc, char const *argv[]) {

  double pi, x, y;
  double r = 1.0;
  unsigned seed0, seed1;
  long Ncirc = 0;

  double start = omp_get_wtime();
  omp_set_num_threads(NUM_THREADS);

  #pragma omp parallel private(seed0,seed1,x,y)
  {
    seed0 = 58472 * (omp_get_thread_num() + 1318);
    seed1 = 27392 * (omp_get_thread_num() + 8281);

    #pragma omp for reduction (+:Ncirc)
    for (long i = 0; i < num_trials; i++) {
      x = -1 + ((double)rand_r(&seed0) / RAND_MAX) * (1 - (-1));
      y = -1 + ((double)rand_r(&seed1) / RAND_MAX) * (1 - (-1));
      if ((x*x + y*y) <= r*r) Ncirc++;
    }
  }

  double end = omp_get_wtime();
  pi = 4.0 * ((double)Ncirc/(double)num_trials);
  printf("%ld trials, pi is %.64g\n",num_trials, pi );
  printf("Time: %g\n", end - start );

  return 0;
}
