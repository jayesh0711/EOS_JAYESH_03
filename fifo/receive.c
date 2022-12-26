#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include<fcntl.h>
int main(int argc,char *const argv[])
{
    int fd;
    unsigned char buff[9000];
    fd=open("/usr/include/stdio.h",O_RDONLY,S_IRUSR|S_IWUSR);
     if(fd==-1)
    {
        perror("error:in opening file");
        exit(EXIT_FAILURE);
    }
    write(fd,buff,9000); 
    if(fd==-1)
    {
        perror("error:in writing file");
        exit(EXIT_FAILURE);
    }
    

    printf("the string are %s",buff);
    close(fd);


}