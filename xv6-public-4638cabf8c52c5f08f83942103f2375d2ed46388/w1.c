#include "types.h"
#include "stat.h"
#include "user.h"

void foo(unsigned long long int s){

    if (s >1 ) {
        printf(1, "TELOS %d\n",s);
        exit();
    }

}

int main(void){
    unsigned long long int counter = 100000;
    unsigned long long int counter2 = 10000;
	unsigned long long int k;
    for (int p = 0; p < 3; p++) {

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
    }
    // printf(1, "k = %d \n",k);
    foo(k);
    exit();

}
