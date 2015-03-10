#include <stdio.h>
#include <errno.h>
#include "helpers.h"

ssize_t read_(int fd, void *buf, size_t count) {
    int total_read = 0;
    int current_read = 0;
    while (current_read = read(fd, buf, count) > 0) {
        total_read += current_read;
	count -= current_read;
	buf += current_read;
    }
    if (current_read == -1) {
        perror("The following error occured");
	return -1;
    }
    return total_read;
}

ssize_t write_(int fd, const void *buf, size_t count) {
    int total_written = 0;
    int current_written = 0;
    while (current_written = write(fd, buf, count) > 0) {
        total_written += current_written;
	count -= current_written;
	buf += current_written;
    }
    if (current_written == -1) {
        perror("The following error occured");
	return -1;
    }
    return total_written;
} 