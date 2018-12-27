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

void foo(unsigned long long int s){

    if (s >1 ) {
        printf(1, "TELOS \n");
        exit();
    }

}


int main(int argc, char *argv[])
{
  int fd ;
  unsigned long long int counter =  100000;
  unsigned long long int counter2 = 10000;
  unsigned long long int k;

  for (int i = 0; i < 5*2*4; i++) {


      if((fd = open("Atext.txt", 0)) < 0){
        printf(1, "cat: cannot open %s\n", argv[i]);
        exit();
      }

      	for (unsigned long long int i=0; i<counter; i++) {
              for(unsigned long long int j=0; j< counter2; j++){
      		    if ((j % 2) == 0){
      			    k = +10000 -999 + 302  + 1000 - 5000 + 4000*2 -2000;//(j%2) +10000 -999 + 302 -  + - 5000 + 4000*2 -200000;
      		    }
      		    else{
      			    k = j%2 + 2 ;
      		    }
              }
      	}




      cat(fd);
      close(fd);
  }
   printf(1, "k = %d \n",k);
    foo(k);
   // printf(1, "TELOS \n");
   exit();
}
