#include <stdio.h>
#include <unistd.h>

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

int main() {
	/*My 239th program in C*/
	/*printf("Hello, World! \n"); */
	      
        int max = 10;
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
         
         return 0;
}
