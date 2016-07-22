#!/bin/bash
# Script of testing

#gcc -o foo test.c -g -finstrument-functions
#chmod +x foo
nm testF > mapping.txt
gcc -c -I. tp.c
gcc -c test.c -finstrument-functions
gcc -o testF test.o tp.o -llttng-ust -ldl

lttng create testF
lttng enable-event -u -a
lttng add-context -u -t vpid -t vtid -t procname
lttng start

LD_PRELOAD=liblttng-ust-cyg-profile.so ./testF > /dev/null
#LD_PRELOAD=/usr/local/lib/liblttng-ust-cyg-profile.so ./testF
#LD_PRELOAD=/usr/lib/x86_64-linux-gnu/liblttng-ust-cyg-profile.so ./testF > /dev/null

lttng stop
lttng destroy
cd /home/frank/lttng-traces/

ls
