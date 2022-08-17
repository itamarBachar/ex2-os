
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int arg, char *argv[]) {
    int fd1;
    int fd2;
    char buf[2];
    char buf2[2];
    int charsr1;
    int charsr2;
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        printf("Error in: open");
        return (-1);
    }
    fd2 = open(argv[2], O_RDONLY);
    if (fd2 == -1) {
        printf("Error in: open");
        return (-1);
    }
    int sign = 1;
    do {
        int whiteSpace1 = 0;
        int whiteSpace2 = 0;
        int lines = 0;
        int lines2 = 0;
        charsr1 = read(fd1, buf, 1);
        if (charsr1 == -1) {
            printf("Error in: read");
            return (-1);
        }
        if ((buf[0] == ' ' || buf[0] == 10 || buf2[0] == 13)  && (charsr1 == 1)) {
            if (buf[0] == ' ') {
                whiteSpace1++;
            } else {
                lines++;
            }
            int flag;
            do {
                flag = 0;
                charsr1 = read(fd1, buf, 1);
                if (charsr1 == -1) {
                    printf("Error in: read");
                    return (-1);
                }
                if ((buf[0] == ' ' || buf[0] == 10 || buf2[0] == 13) && (charsr1 == 1)) {
                    if (buf[0] == ' ') {
                        whiteSpace2++;
                    } else {
                        lines2++;
                    }
                    flag = 1;
                }
            } while (flag);
        }
        charsr2 = read(fd2, buf2, 1);
        if (charsr2 == -1) {
            printf("Error in: read");
            return (-1);
        }
        if ((buf2[0] == ' ' || buf2[0] == 10 || buf2[0] == 13)  && (charsr2 == 1)) {
            int flag;
            if (buf2[0] == ' ') {
                whiteSpace2++;
            } else {
                lines2++;
            }
            do {
                flag = 0;
                charsr2 = read(fd2, buf2, 1);
                if (charsr2 == -1) {
                    printf("Error in: read");
                    return (-1);
                }
                if ((buf2[0] == ' ' || buf2[0] == 10 || buf2[0] == 13) && (charsr2 == 1)) {
                    if (buf2[0] == ' ') {
                        whiteSpace2++;
                    } else {
                        lines2++;
                    }
                    flag = 1;
                }
            } while (flag);
        }
        if (buf2[0] == buf[0] && sign == 1 && whiteSpace1 == whiteSpace2 && lines == lines2) {
            sign = 1;
        } else if ((buf2[0] + 32) == buf[0] || (buf2[0] - 32) == buf[0] || buf2[0] == buf[0]) {
            sign = 2;
        } else {
            sign = 3;
            break;
        }
    } while (charsr1 == 1 && charsr2 == 1);
    if (charsr1 == 1) {
        do {
            charsr1 = read(fd1, buf, 1);
            if ((buf[0] == ' ' || buf[0] == 10 || buf2[0] == 13) && (charsr1 == 1)) {
                continue;
            }
            else{
                sign = 3;
            }
        } while (charsr1 == 1);
    }
    if (charsr2 == 1) {
        do {
            charsr2 = read(fd2, buf2, 1);
            if ((buf2[0] == ' ' || buf2[0] == 10 || buf2[0] == 13) && (charsr2 == 1)) {
                continue;
            }
            else{
                sign = 3;
            }
        } while (charsr2 == 1);
    }
    int check = close(fd1);
    if (check == -1) {
        printf("Error in: close");
        return (-1);
    }
    int check2 = close(fd2);
    if (check == -1) {
        printf("Error in: close");
        return (-1);
    }
    return sign;
}


