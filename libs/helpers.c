#include <stdio.h>
#include <errno.h>

ssize_t read_(int fd, void *buf, size_t count) {
    int total_read = 0;
    int current_read;
    while (current_read = read(fd, buf, count) > 0) {
        total_read += current_read;
    }
    if (now_read < 0) {
        perror("The following error occured");
    }
    return total_read;
}

ssize_t write_(int fd, const void *buf, size_t count) {
    int total_written = 0;
    int current_written;
    while (now_written = write(fd, buf, count) > 0) {
        total_written += current_written;
    }
    if (now_written < 0) {
        perror("The following error occured");
    }
    return total_written;
} 