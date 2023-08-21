#include "../minishell.h"

/*
    signum: The signal you want to handle. For example, SIGINT for Ctrl + C.
    handler: A pointer to the function that should be executed when the 
    specified signal is received. The function takes an integer parameter that 
    represents the signal number.
*/

void signal_handler(int signal_num)
{
    // queda por hacer
    // liberar toda la memoria del t_content antes del exit
    printf("Received SIGINT (Ctrl+C)\n");
    exit(signal_num);
}

void custom_exit(t_content *cont, int i)
{
    cont[i].signal_sent = 1;
    //signal(SIGINT, signal_handler);
    //kill(cont[i].global->main_getpid, SIGTERM);   
}// esto no funciona bien creo que porque esta comentada la linea rl_replace_line