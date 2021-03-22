// print the compilation command to 
//  link libjpeg.so and 
//  produce the executable vizplus
#include <stdio.h>
int main(){
    printf("gcc -std=c11 -Wall -fmax-errors=10 -Wextra vizplus.c -ljpeg -o vizplus");
}