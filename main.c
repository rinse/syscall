
#include <asm/unistd.h>

static int errno;

int write(const void* buf, unsigned long count) {
  long res;

  __asm__ volatile ("syscall"
      : "=a"(res)
      : "0"(__NR_write), "D"((long)1), "S"((long)buf), "d"((long)count)
      : "r11", "rcx", "memory"
    );

  if ((unsigned long) res >= (unsigned long) -127) {
    errno = -(res);
    res = -1;
  }

  return (int) res;
}

void exit(int code) {
  long res;
  __asm__ volatile ("syscall"
      : "=a"(res)
      : "0"(__NR_exit), "D"((long)code)
    );
}

void __main() {
  write("Hello, world!\n", 14);
  exit(0);
}

