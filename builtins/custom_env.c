#include "../minishell.h"

void custom_env(void)
{
    printf("get the path\n");
    getenv("PATH");
    printf("%s\n", getenv("USER"));
}