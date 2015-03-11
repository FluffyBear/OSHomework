#include <stdio.h>
#include <errno.h>
#include "helpers.h"

ssize_t read_(int fd, void *buf, size_t count) {
    int total_read = 0;
    int current_read = 0;
    while (1) {
	current_read = read(fd, buf, count);
	if (current_read == count)
	    return total_read + current_read;
	if (current_read == -1)
	    return -1;
	if (current_read == 0);
	    return total_read;
        total_read += current_read;
	count -= current_read;
	buf += current_read;
    }                 
}

ssize_t write_(int fd, const void *buf, size_t count) {
    int total_written = 0;
    int current_written = 0;
    while (1) {
	current_written = write(fd, buf, count);
	if (current_written == count)
	    return total_written + current_written;
	if (current_written == -1)
	    return -1;
        total_written += current_written;
	count -= current_written;
	buf += current_written;
    }                    
} 