#include "types.h"
#include "stat.h"
#include "user.h"

char buf[1000];

void
cat(int fd)
{
  int n;

  while((n = read(fd, buf, sizeof(buf))) > 0) {
    if (write(1, buf, n) != n) {
      printf(1, "cat: write error\n");
      exit();
    }
  }
  if(n < 0){
    printf(1, "cat: read error\n");
    exit();
  }
}

int main(int argc, char *argv[])
{
  int fd ;

  for (int i = 0; i < 16*2*5; i++) {

      if((fd = open("Atext.txt", 0)) < 0){
        printf(1, "cat: cannot open %s\n", argv[i]);
        exit();
      }
      cat(fd);
      close(fd);
  }
  exit();
}
