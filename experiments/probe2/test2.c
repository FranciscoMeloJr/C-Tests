#include <stdio.h>
#include <unistd.h>

#include "tp.h"

void baz(){
	usleep(1000);
        printf("\n baz \n");
        
}
void bar(){
	usleep(1000);
        printf("\n bar \n");
        baz();
}
void foo(){
	usleep(1000);
	printf("\n foo \n");
	bar();
}

int main() {
	/*My 239th program in C*/
	/*printf("Hello, World! \n"); */
	      
        int max = 100;
        for (int i = 0; i < max; i++) {
                // tracepoint interval_begin, foo_provider 
                tracepoint(interval, tracepoint, 1, "begin");              

		foo();
        	bar();
	        baz();

                tracepoint(interval, tracepoint, 2, "end");

                //tracepoint interval_end
	}       

	return 0;
}
