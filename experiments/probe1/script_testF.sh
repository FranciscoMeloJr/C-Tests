#!/bin/bash
# Script of testing

gcc -o testF test.c -g -finstrument-functions
chmod +x testF
nm testF > mapping.txt

lttng create testF
lttng enable-event -u -a
lttng add-context -u -t vpid -t vtid -t procname
lttng start

LD_PRELOAD=/usr/local/lib/liblttng-ust-cyg-profile.so ./testF

lttng stop
lttng destroy
cd /home/frank/lttng-traces/
clear

ls
