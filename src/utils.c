#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "utils.h"


/*
 * Find index of char in a char *
 * returns idx of char
 */
int str_find(char *s, char c) {
    int idx = 0;
    while(*s != '\0') {
        if(*s == c) {
            return idx;
        }
        idx++;
        s++;
    }
    return -1;
}

/*
 * Read a file content into a buffer
 * returns buffer with file content
 */
char* read_file(char *file_name, char* buffer, size_t buff_size, size_t offset) {
    int fd = open(file_name, O_RDONLY);

    if(fd && buffer) {
        /*
        size_t size = buff_size;
        if(buff_size == -1) {
            fseek(f, 0, SEEK_END);
            // make sure the file size is less than 2G
            size = ftell(f);
            fseek(f, 0, SEEK_SET);
        }
        */

        pread(fd, buffer, buff_size, offset);
        close(fd);
        return buffer;
    }
    return NULL;
}
