#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {

  int ret = getpinfo();

  if (ret == -1) {
    printf(1, "\tps failed\n");
    exit();
  }
  exit();
}
