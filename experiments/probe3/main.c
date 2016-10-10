#include <stdio.h>

void baz() {
 printf("foo\n");
}


void bar() {
 printf("foo\n");
 baz();
}


void foo() {
 printf("foo\n");
 bar();
}
 
int main() {
 
 foo();
 
 return 0;
}
