#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "tp.h"

//Perf:
#include <linux/perf_event.h>
#include <sys/syscall.h>
#include <unistd.h>
/* perf_event_open syscall wrapper */
static long
sys_perf_event_open(struct perf_event_attr *event,
                    pid_t pid, int cpu, int group_fd, unsigned long flags)
{
    return syscall(__NR_perf_event_open, event, pid, cpu, group_fd, flags);
}

static inline pid_t gettid()
{
    return syscall(SYS_gettid);
}

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

//fulfil the array:
void fulfil(char *buf, int size){
  
  int i = 0;

  for(i =0; i< size; i++){
      buf[i] = 'a';
  }
}

//step over the array:
//fulfil the array:
double walk(char *buf, int step, int size){

  int i = 0;
  double sum =0;
  for(i =0; i< size; i+=step){
      sum += buf[i];
  }
}

int main() {
	/*My 239th program in C*/
	/*printf("Hello, World! \n"); */
	      
        /*int max = 10;
        for (int i = 0; i < max; i++) {
                // tracepoint interval_begin, foo_provider 
                tracepoint(cct, tracepoint, 1, "begin");              
                tracepoint(cct, getinfo, i, i*2, "cache");
                usleep(1000 * i);

		foo(i);
        	bar(i);
	        baz(i);

                tracepoint(cct, tracepoint, 2, "end");

                //tracepoint interval_end
	}       
         
         tracepoint(cct, tracepoint, 2, "context");
 	*/
        printf("Cache Size test");

        // core dumped: int size = 10000000;
        int size = 1000000;
	char buffer[size];
        char *tbl[] = { "1", "2", "3" };
         
	fulfil(buffer, size);	
	size_t len = sizeof(buffer);
        printf("Buffer's size is %lu \n", len);

        int j = 0;
       
       
        for(j = 0; j < 10; j++){
        int step = 1;
        double result = 0;
        clock_t delta;
        double time_taken = 0;
        for(step = 1; step < 1000; step++){        
          delta = clock();
          result =  walk(buffer, step, size);
          delta = clock() - delta;
          time_taken = ((double)delta)/CLOCKS_PER_SEC;

          printf("Step %d is %.3f x: %lu time: %lf => bytes/seg: %.3f\n", step, result, delta, time_taken, (double) step/time_taken);
          
	}
        //test size:
        char tab[7]={'a','b','t','u','a','y','t'};
        printf("Test size of 7 is %lu\n",sizeof(tab));
	}
        return 0;

}
