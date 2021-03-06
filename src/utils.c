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
 * Read a file content into a malloc buffer
 * returns buffer with file content
 */
char* read_file(char *file_name) {
    FILE *f = fopen(file_name, "r");

    if(f) {
        fseek(f, 0, SEEK_END);
        // make sure the file size is less than 2G
        size_t size = ftell(f);
        fseek(f, 0, SEEK_SET);
        char *buffer = malloc(sizeof(char) * size);
        fread(buffer, sizeof(char), size, f);
        fclose(f);
        return buffer;
    }
    return NULL;
}
