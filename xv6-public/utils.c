#include "types.h"
#include "defs.h"

static uint seed = 1;

void
srand(uint s)
{
  seed = s;
}

int
rand(void)
{
    seed = seed
        * 1103515245
        + 12345
        % (1 << 31);
    return seed;
}
