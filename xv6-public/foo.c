#include "types.h"
#include "user.h"

#define PROCS_NUM 5

int main() {
    for (int i = 0; i < PROCS_NUM; ++i) {
        int pid = fork();
        if (pid > 0)
            continue;
        if (pid == 0) {
            for (long j = 0; j < 1000000000; ++j) {
                int x = 1;
                x++;
            }
            exit();
        }
    }
    while (wait() != -1)
        ;
    exit();
}
