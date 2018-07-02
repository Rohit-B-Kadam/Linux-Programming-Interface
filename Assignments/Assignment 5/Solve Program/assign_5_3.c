#include <sched.h>
#include <stdio.h>

int main()
{
    printf("Before yield process\n");
    sched_yield();
    printf("After yield process\n");
    return 0;
}