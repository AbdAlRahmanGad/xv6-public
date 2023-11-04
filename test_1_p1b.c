#include "types.h"
#include "stat.h"
#include "user.h"


int
main(int argc, char *argv[]) {
  int x1 = getreadcount();
     printf(1, "XV6_TEST_OUTPUT %d\n", x1);
  int x2 = getreadcount();
     printf(1, "XV6_TEST_OUTPUT %d\n", x2);

  char buf[100];
  (void) read(4, buf, 1);
  int x3 = getreadcount();
     printf(1, "XV6_TEST_OUTPUT %d\n", x3);

  int i;
  for (i = 0; i < 1000; i++) {
    (void) read(4, buf, 1);
  }
  int x4 = getreadcount();
     printf(1, "XV6_TEST_OUTPUT %d\n", x4);

  printf(1, "XV6_TEST_OUTPUT %d %d %d\n", x2-x1, x3-x2, x4-x3);
  printf(1, "XV6_TEST_OUTPUT %d %d %d\n", x2, x3, x4);
  exit();
}
