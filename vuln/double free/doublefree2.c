#include<stdio.h>
#include<malloc.h>

char *p = 0;
int main(){
    p = malloc(504);
    char *q = malloc(512);
    printf("%p\n", p);
    printf("%p\n", q);
    printf("p at %p\n", &p);
    free(p);
    free(q);
    char *p1 = malloc(768);
    printf("p1 = %p\n", p1);
    p1[0] = 0x0;
    p1[1] = 0x0;
    p1[2] = 0x0;
    p1[3] = 0x0;
    p1[4] = 0xf9;
    p1[5] = 0x01;
    p1[6] = 0x0;
    p1[7] = 0x0;
    p1[8] = 0x20;
    p1[9] = 0xa0;
    p1[10] = 0x04;
    p1[11] = 0x08;
    p1[12] = 0x24;
    p1[13] = 0xa0;
    p1[14] = 0x04;
    p1[15] = 0x08;
    p1[504] = 0xf8;
    p1[505] = 0x01;
    p1[506] = 0x0;
    p1[507] = 0x0;
    p1[508] = 0x08;
    p1[509] = 0x01;
    p1[510] = 0x0;
    p1[511] = 0x0;
    free(q);
    printf("p = %p\n", p);
    return 0;


}
