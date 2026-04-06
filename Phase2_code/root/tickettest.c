#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <linux/getticket.h>

int main(int argc, char *argv[]) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);
    int ticket;

    if (syscall(__NR_getticket, pid, &ticket) == -1) {
        perror("sys_getticket");
        return 1;
    }

    printf("Process %d has %d tickets.\n", pid, ticket);
    */
    return 0;
}

