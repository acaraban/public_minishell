#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int i;

	i = 0;
	char *j = NULL;
	while (i < 8)
	{
		if (!j)
			printf("no existe j\n");
		i++;
	}
}

