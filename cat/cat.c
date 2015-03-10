#include "../lib/helpers.h"
#include <errno.h>
#include <unistd.h>  
         
int main(int argc, char* argv[]) {
    char buf[1024];
    ssize_t read_res = 0;
    ssize_t write_res = 0;

    while(read_res = read_(STDIN_FILENO, buf, sizeof(buf)) > 0) {
        write_res = write_(STDOUT_FILENO, buf, read_res);
        if(write_res == -1) {
            perror("The following error occurred");
            exit(1);
        }
   }

   if(read_res == -1) {
        perror("The following error occurred");
        exit(1);
   }
   return 1;
}