#include "../minishell.h"

/*

getenv() te deja pasarle un argumento, ejemplo: getenv("PATH")
y puedes imprimir eso. pero no se le puede pasar vacío
//getenv("PATH");
//printf("%s\n", getenv("USER"));

*/

void custom_env(t_content *content, int i)
{
    int j;

    j = 0;
    while(content[i].global->env[j])
	{
		printf("%s\n", content[i].global->env[j]);
		j++;
	}
    // prueba añadir otra variable en plan export
    //content[i].global->env[j] = "MARIA_VAR_FOREVER=ahora";
}