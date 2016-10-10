lttng create test3
lttng enable-event -u -a
#lttng add-context -u -t vpid -t vtid -t procname
lttng start

LD_PRELOAD=/usr/local/lib/liblttng-ust-cyg-profile.so ./hello

lttng stop
lttng destroy
cd /home/frank/lttng-traces/
clear

ls
