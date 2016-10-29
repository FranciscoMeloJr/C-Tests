##This script compiles and execute the test.c file with hello-tp tracepoints:
## This test generates 10 trees that can be compared

#compilation:
gcc -c -I. tp.c
gcc -finstrument-functions -c read.c
gcc -o testRead read.o tp.o -llttng-ust -ldl
./testRead text1.txt

#execution:
#lttng create test3
#lttng enable-event -u -a
#lttng add-context -u -t vpid -t vtid -t procname
#lttng start

#LD_PRELOAD=/usr/local/lib/liblttng-ust-cyg-profile.so ./testCache

#lttng stop
#lttng destroy
#cd /home/frank/lttng-traces/
#clear

ls

