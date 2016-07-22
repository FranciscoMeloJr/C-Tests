#!/bin/bash
# Script of testing a generic program, which will be compiled with finstruments

#gcc -o foo test.c -g -finstrument-functions
#chmod +x foo

echo "This scripts records a trace from a generic .c program, which is compiled with -finstruments"
echo "Enter a .c file"
read name

gcc -o $name $name.c -g -finstrument-functions
chmod +x $name


nm $name > mapping.txt

lttng create $name
lttng enable-event -u -a
lttng add-context -u -t vpid -t vtid -t procname
lttng start

LD_PRELOAD=/usr/local/lib/liblttng-ust-cyg-profile.so ./$name

lttng stop
lttng destroy
cd /home/frank/lttng-traces/
clear

ls
