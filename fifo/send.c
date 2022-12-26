 #include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include <stdlib.h>

int main(int argc,char *const argv[])
{   
    int count=0;
    int fd,i;
    unsigned char buff[9000];
    fd=open("/usr/include/stdio.h",O_RDONLY,S_IRUSR|S_IWUSR);
    if(fd==-1)
    {
        perror("error:in opening file\n");
        exit(EXIT_FAILURE);
    }
    read(fd,buff,9000);
     if(fd==-1)
    {
        perror("error:in reading file\n");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<sizeof(buff);i++)
    {
          if(buff[i]=='s')
          {
             count++;
             //printf("the number of letter of s:%d",count);
          }
    }
     printf("the number of letter of s:%d\n",count);
    printf("the string are %s",buff);
    close(fd);


}