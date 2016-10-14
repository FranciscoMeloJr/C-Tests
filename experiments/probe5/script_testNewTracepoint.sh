##This script compiles and execute the test.c file with hello-tp tracepoints:
## This test generates 10 trees that can be compared

#compilation:
gcc -c -I. tp.c
gcc -finstrument-functions -c testNewTracepoint.c
gcc -o testNTP testNewTracepoint.o tp.o -llttng-ust -ldl
./testNTP

#execution:
lttng create test3
lttng enable-event -u -a
#lttng add-context -u -t vpid -t vtid -t procname
lttng start

LD_PRELOAD=/usr/local/lib/liblttng-ust-cyg-profile.so ./testNTP

lttng stop
lttng destroy
cd /home/frank/lttng-traces/
clear

ls

