#include<stdlib.h>
#include<time.h>

int main() {
  srand(time(NULL));
  double x = rand() / (double)RAND_MAX;
  return 0;
}