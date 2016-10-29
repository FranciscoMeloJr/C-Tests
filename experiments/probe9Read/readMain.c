#include <stdio.h>
#include <stdlib.h> // For exit() function

void read(char* argument){
    char c[1000];
    FILE *fptr;

    //read:
    if ((fptr = fopen(argument, "r")) == NULL)
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
//Main:
int main(int argc, char *argv[])
{
     
    read(argv[1]);    
    return 0;
}
