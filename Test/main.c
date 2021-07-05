#include <stdio.h>
int check( char *ptr);


int main(void) {
char *ptr="Blue";
check(ptr);
printf("%s \n",ptr);
return 0;
}

int check( char *ptr) {
ptr="Yellow";
return 0;
}
