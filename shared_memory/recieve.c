#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/mman.h>
#include<fcntl.h>
char *count_r;
int main()
{
    int count=0;
    int fd;
    fd=shm_open("/usr/include/stdio.h",O_RDWR,S_IRUSR|S_IWUSR);
    ftruncate(fd,sizeof(char));
    count_r =(char*)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    {
        while(1)
        {
            if(*count_r=='s')
            {
            (*count_r)++;
            count++;
            printf("sending count:%d\n",(*count_r));
            printf("the number of occurance of s :%d",count);
            sleep(1);
        }
    }
    return 0;
    }
    
}