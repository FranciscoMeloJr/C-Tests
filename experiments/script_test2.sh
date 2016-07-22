#!/bin/bash
# Script of testing

echo "Test tracing with test.c"
echo -n "Enter the name of the tracing"
read name

echo -n "Enter the name of the program, already copiled"
read program

lttng create $name
lttng enable-event -u -a
lttng add-context -u -t vpid -t vtid -t procname
lttng start

LD_PRELOAD=/usr/local/lib/liblttng-ust-cyg-profile.so ./$program

nm $program > mapping.txt

lttng stop
lttng destroy
cd /home/frank/lttng-traces/
clear

ls
