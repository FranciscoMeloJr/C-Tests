#include <stdio.h>
#include <stdlib.h>
 
void foo(int i)
{
    printf("Foo - Hello, I'm a shared library %d", i);
}

void bar(int i)
{
    puts("Bar - Hello, I'm a shared library");
}

void baz(void)
{
    puts("Baz - Hello, I'm a shared library");
}

void read(char* arg){

  char c[1000];
  FILE *fptr;

  if ((fptr = fopen(arg, "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    // reads text until newline 
    fscanf(fptr,"%[^\n]", c);

    printf("Data from the file:\n%s", c);
    fclose(fptr);

}
