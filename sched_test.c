#include "stat.h"
#include "types.h"
#include "user.h"
// sched_test 5 100

int main(int argc, char *argv[]) {
  if (argc != 3) {
    exit();
  }
  settickets(atoi(argv[1]));
  int rc = fork();
  for (int i = 0; i < atoi(argv[2]); i++) {
    printf(1, "\tnum %d\n", i);
    printf(1, "\tfork %d\n", rc);
  }
  exit();
}
