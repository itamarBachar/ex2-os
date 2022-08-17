#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

//
// Created by itamar on 5/1/22.
//
int main(int arg, char *argv[]) {
    char firstPath[150];
    int i = 0;
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf("Error in: chdir");
        return (-1);
    }
    do {
        fd = read(fd, &firstPath[i], 1);
        if (fd == -1) {
            printf("Error in: read");
            return (-1);
        }
        if (firstPath[i] == 10) {
            firstPath[i] = 0;
            break;
        }
        i++;
    } while (1);
    fd = read(fd, &firstPath[i], 1);



}

