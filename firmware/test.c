#include<stdlib.h>
#include<stdio.h> 

void printb(unsigned char num) {
    unsigned int size = sizeof(unsigned char);
    unsigned int maxPow = 1<<(size*8-1);
    
    for(int i=0;i<size*8;++i){
        // print last bit and shift left.
        if (i % 4 == 0)
            printf(" ");
        printf("%u",num&maxPow ? 1 : 0);
        num = num<<1;
    }
    printf("\n");
}

void main() {
    unsigned char a = 5;
    printb(a);
    a = (a << 1);
    printb(a);
    a = (a << 1);
    printb(a);
    a = (a << 1);
    printb(a);
    a = (a << 1);
    printb(a);

    printf("=-----------------=\n");

    u_int8_t b = 5;
    printb(b);
    b |= 8;
    printb(b);
    b &= 8;
    printb(b);
    b != 8;
    printb(b);
}
