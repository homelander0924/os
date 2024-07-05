// open()
// /C program to illustrate
// open system call
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int errno;
int main()
{
    // if file does not have in directory
    // then file foo.txt is created.
    int fd = open("foo.txt", O_RDONLY | O_CREAT);
    printf("fd = %d\n", fd);
    if (fd == -1)
    {
        // print which type of error have in a code
        printf("Error Number % d\n", errno);
        // print program detail "Success or failure"
        perror("Program");
    }
    return 0;
}

// close()
// C program to illustrate close system Call
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    int fd1 = open("foo.txt", O_RDONLY);
    if (fd1 < 0)
    {
        perror("c1");
        exit(1);
    }
    printf("opened the fd = % d\n", fd1);
    // Using close system Call
    if (close(fd1) < 0)
    {
        perror("c1");
        exit(1);
    }
    printf("closed the fd.\n");
}

// read()
#include <unistd.h>
int main()
{
    int fd, sz;
    char *c = (char *)calloc(100, sizeof(char));
    fd = open("foo.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("r1");
        exit(1);
    }
    sz = read(fd, c, 10);
    printf("called read(% d, c, 10). returned that"
           " %d bytes were read.\n",
           fd, sz);
    c[sz] = '\0';
    printf("Those bytes are as follows: % s\n", c);
    return 0;
}
// write()
// C program to illustrate
// write system Call
#include <stdio.h>
#include <fcntl.h>
main()
{
    int sz;
    int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("r1");
        exit(1);
    }
    sz = write(fd, "hello skillvertex\n", strlen("hello skillvertex\n"));
    printf("called write(% d, \"hello skillvertex\\n\", %d)."
           " It returned %d\n",
           fd, strlen("hello skillvertex\n"), sz);
    close(fd);
}

// fork()
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()

{
    // make two process which run same
    // program after this instruction
    pid_t p = fork();
    if (p < 0)
    {
        perror("fork fail");
        exit(1);
    }
    printf("Hello world!, process_id(pid) = %d \n", getpid());
    return 0;
}