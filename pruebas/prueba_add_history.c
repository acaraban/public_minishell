
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/*int main (void)
{
	char **jj;
	char ***pr;
	int i;
	i= 0;

	jj = (char **)malloc(sizeof(char *) * 4);
	jj[0] = strdup("primera linea");
	jj[1] = strdup("segunda linea");
	jj[2] = strdup("tercera linea");;
	jj[3] = NULL;
	free(jj[1]);
	jj[1] = strdup("cambio");
	while (jj[i] )
		printf("%s\n", jj[i++]);

	pr = (char ***)malloc(sizeof(char **) * 4);
	pr[0] = &jj[2];
	printf("este es el triple puntero: %s\n", pr[0][0]);
}*/