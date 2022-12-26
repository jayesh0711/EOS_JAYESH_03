#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<sys/stat.h>
char *count_s;
int main()
{
    int fd;
    fd=shm_open("/usr/include/stdio.h",O_RDWR,S_IRUSR|S_IWUSR);
    ftruncate(fd,sizeof(char));
    count_s =(char*)mmap(NULL,sizeof(char),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    *count_s=0;
    {
        while(1)
        {
            (*count_s)++;
            printf("sending count:%d\n",(*count_s));
            sleep(1);
        }
    }
    return 0;

}