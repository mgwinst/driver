#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd = open("/dev/test_cdev", O_RDONLY);
    if (fd < 0) {
        perror("failed to open /dev/test_cdev");
        return 1;
    }

    printf("file descriptor for open /dev/test_cdev: [%d]\n", fd);
    close(fd);

    return 0;
}
