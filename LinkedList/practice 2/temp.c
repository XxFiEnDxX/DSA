#include<stdio.h>
void main(){
    int x = 99;
    int *ptr;

    ptr = &x;

    printf("Value of ptr is %d \n",*ptr);

    printf("Address pointed by ptr is  %p \n",ptr);
}