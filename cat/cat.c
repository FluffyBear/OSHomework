#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <helpers.h> 
         
int main() {
    char buf[4096];
    ssize_t read_res = 0;
    ssize_t write_res = 0;

    while(1) {
	read_res = read_(STDIN_FILENO, buf, sizeof(buf));
	if (read_res == -1)
            perror("The following error occurred");
	    return 1;
	}
	    
        write_res = write_(STDOUT_FILENO, buf, read_res);
        if(write_res == -1) {
            perror("The following error occurred");
            return 1;
        }
	if (rres < sizeof(buf))
	    return 0;
   }                
}
