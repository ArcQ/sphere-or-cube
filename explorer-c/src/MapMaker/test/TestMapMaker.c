#include <stdio.h>
#include "minunit.h"
#include "MockDriver.c"
#include "Vector.h"

int tests_run = 0;

Vector vectorOne = { {2,2}}

static char * test_move() {
  struct DriverState state = getDriverState();
  printf("%f\n", state.orientation);
  state.orientation = 1;
  printf("%f\n", state.orientation);
  mu_assert("should move forward if not hitting a barrier", bar == 5);
  return 0;
}

static char * test_stop() {
  mu_assert("hitting 4 barriers should stop algorithm", foo == 7);
  return 0;
}

static char * test_turn() {
  mu_assert("hitting a barrier should turn", foo == 7);
  return 0;
}

static char * test_calcDist() {
  mu_assert("hitting a barrier should calculate distance from beginning point", bar == 5);
  return 0;
}

static char * test_finish() {
  mu_assert("hitting 4 barriers should finish algorithm", foo == 7);
  return 0;
}


static char * all_tests() {
  mu_run_test(test_move);
  mu_run_test(test_stop);
  mu_run_test(test_turn);
  mu_run_test(test_calcDist);
  mu_run_test(test_finish);
  return 0;
}

int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("FAILED %s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}
