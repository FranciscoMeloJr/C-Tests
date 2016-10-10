#!/bin/bash
# Script of testing

#gcc -o foo test.c -g -finstrument-functions
#chmod +x foo
#nm testF > mapping.txt

lttng create test3
lttng enable-event -u -a
lttng add-context -u -t vpid -t vtid -t procname
lttng start

LD_PRELOAD=/usr/local/lib/liblttng-ust-cyg-profile.so ./main

lttng stop
lttng destroy
cd /home/frank/lttng-traces/
clear

ls
