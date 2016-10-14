#include <stdio.h>
#include <unistd.h>

#include "tp.h"

void baz(int i){
	usleep(1000*i);
        printf("\n baz \n");
        
}
void bar(int i){
	usleep(1000*i);
        printf("\n bar \n");
        baz(i);
}
void foo(int i){
	usleep(1000*i);
	printf("\n foo \n");
	bar(i);
}

int main() {
	/*My 239th program in C*/
	/*printf("Hello, World! \n"); */
	      
        int max = 10;
        for (int i = 0; i < max; i++) {
                // tracepoint interval_begin, foo_provider 
                tracepoint(interval, tracepoint, 1, "begin");              
                tracepoint(interval, getinfo, i, "cache");
                usleep(1000 * i);

		foo(i);
        	bar(i);
	        baz(i);

                tracepoint(interval, tracepoint, 2, "end");

                //tracepoint interval_end
	}       
         
         tracepoint(interval, tracepoint, 2, "context");
         
         return 0;
}
