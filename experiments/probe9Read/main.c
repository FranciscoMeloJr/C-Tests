#include <stdio.h>
#include "foo.h"
 
int main(void)
{
    puts("This is a shared library test...");
    foo(10);
    return 0;
}
