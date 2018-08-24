#include <stdio.h>

_Pragma("GCC diagnostic push")
_Pragma("GCC diagnostic ignored \"-Wunused-parameter\"")

int main(int argc, const char *argv[])
{
    while (*++argv) puts(*argv);
    return 0;
}
_Pragma("GCC diagnostic pop") \
