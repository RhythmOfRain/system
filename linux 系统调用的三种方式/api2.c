#include<stdio.h>
#include<unistd.h>
#include<sys/syscall.h>
#include<errno.h>

int main(int argc, char *argv[]){
    int rc;
    rc = syscall(SYS_chmod, argv[1], 0444);
    if(rc == -1)
	fprintf(stderr, "chmod failed, errno = %d\n", errno);
    else
	printf("chmod success!\n");
    return 0;
}
