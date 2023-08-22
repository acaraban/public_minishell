//#include "../minishell.h"

/*
    signum: The signal you want to handle. For example, SIGINT for Ctrl + C.
    handler: A pointer to the function that should be executed when the 
    specified signal is received. The function takes an integer parameter that 
    represents the signal number.
    use write instead of printf because last one it doesnt work properly on signals
*/

/*void signal_handler(int signal_num)
{
	pid_t parent_pid; // pruebas
    
    // queda por hacer
    // liberar toda la memoria del t_content antes del exit
    write(1, "Received SIGUSR1\n", 17);
    // antes de este exit , manda un kill 
    
    // desde aqui como envio el kill al padre?
    parent_pid = getppid(); // no se puede usar getppid()
    kill(parent_pid, SIGTERM);
    exit(signal_num);
}*/

/*
    info->si_pid es la info del padre
*/

void custom_sigaction(int signal_num, siginfo_t *info, void *context)
{
    (void)context;
    write(1, "Received SIGUSR1 in custom sigaction\n", 38);
    //kill(info->si_pid, SIGTERM);
    kill(info->si_pid, SIGUSR2);
    exit(signal_num); // es necesario el exit ??
}

/*

    infinite loop to keep waiting inside this function until signal is received
*/

//void custom_exit(t_content *cont, int i)
void custom_exit(void)
{
    // CHILD receives signal SIGUSR1
    // signal_handler es para definir que hace esta señal SIGUSR1
    //signal(SIGUSR1, signal_handler); 
    // en vez de signal debe ser sigaction
    // para saber pid del padre
    // hay configurar struct de sigaction
    struct sigaction sa;
    //sa.sa_handler = signal_handler; // esto no seria
    sa.sa_sigaction = custom_sigaction; // seria asi
    sigemptyset(&sa.sa_mask); // Clear the signal mask
    sa.sa_flags = SA_SIGINFO; // super important, aqui viene toda la info de la señal
    // set up a signal handler for SIGUSR1 in child process
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        return ; // return ?
    }
    // hasta aqui sigaction
    printf("justo antes de signal (Ctrl+C)\n");
    while (1)
    {
        // while infinito para que se quede esperando dentro de custom_exit
        // hasta que llegue la señal que esta esperando recibir
    }

    
      
}