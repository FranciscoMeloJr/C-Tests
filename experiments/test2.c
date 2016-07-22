#include <stdio.h>
#include <unistd.h>

void baz(){
	usleep(1000);
        printf("\n baz \n");
        
}
void bar(){
	usleep(1000);
        printf("\n bar \n");
        baz();
}
void foo(){
	usleep(1000);
	printf("\n foo \n");
	bar();
}
int main() {
	/*My 239th program in C*/
	printf("Hello, World! \n");
	for (int i = 0; i < 10; i++) {
		foo();
	}
	return 0;
}
