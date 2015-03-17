#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <helpers.h>

void reverse(char* word, int pos) {
    int i;
    for(i = 0; i < pos / 2; i++) {
        char ch = word[i];
        word[i] = word[pos - i - 1];
        word[pos - i - 1] = ch;
    }
}

int main() {
    char buffer[4096];
    char word[4096];
    ssize_t pos = 0;
    ssize_t current_read = 0;
    while(1) {
        if ((current_read = read_until(STDIN_FILENO, buffer, sizeof(buffer), ' ')) == -1) {
            perror("The following error occurred");
            return 1;
        }
        if (current_read == 0) {
           if (pos != 0) {
               reverse_word(word, pos);
               write_(STDOUT_FILENO, word, pos);
           }           
           return 0;
        }   
        int i;
        for (i = 0; i < current_read; i++)
            if (buffer[i] == ' ') {
                if (pos != 0) {
                    reverse(word, pos);
                    write_(STDOUT_FILENO, word, pos);
                }
                char ch = ' ';                        
                pos = 0;                   
                write_(STDOUT_FILENO, &ch, 1);
            } else {
                word[pos] = buffer[i];
                pos++;
            }
    }
    return 0;
    
}