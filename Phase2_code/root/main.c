#include <stdio.h>
#include <stdlib.h>
#include <linux/changeflag.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sched.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {
    int flag = 1;
    changeflag(flag);

    return 0;
}
