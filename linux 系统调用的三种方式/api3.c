#include<stdio.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include<errno.h>

int main(int argc, char *argv[]){
    long rc;
    char *file_name = argv[1];
    unsigned short mode = 0444;
    asm(
        "int $0x80"
	: "=a" (rc)
	: "0" (SYS_chmod), "b"((long)file_name), "c"((long)mode)
       );
    if((unsigned long)rc >= (unsigned long)-132){
	    errno = -rc;
	    rc = -1;
    }
    if(rc == -1)
        fprintf(stderr, "chmod failed, errno = %d\n", errno);
    else
	printf("success!\n");
    return 0;
}


