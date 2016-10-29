gcc -c -Wall -Werror -fpic foo.c
gcc -shared -o libfoo.so foo.o
gcc -Wall -o test main.c -lfoo
gcc -L/home/frank/Desktop/C-Tests/experiments/probe9Read -Wall -o test main.c -lfoo

echo 'Ideology'
./test
