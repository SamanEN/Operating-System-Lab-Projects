#include "types.h"
#include "user.h"

#define PROCS_NUM 5

int main()
{
    for (int i = 0; i < PROCS_NUM; ++i)
    {
        int pid = fork();
        if (pid > 0)
            continue;
        if (pid == 0)
        {
            if (i == PROCS_NUM)
                sleep(8000);
            else
                sleep(1000);
            for (int j = 0; j < 2 * i; ++j)
            {
                int x = 1;
                for (long k = 0; k < 1000000000; ++k)
                    x++;
            }
            exit();
        }
    }
    while (wait() != -1)
        ;
    exit();
}