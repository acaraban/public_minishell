#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*rtn;

	if (!s1 && !s2)
		return (strdup(""));
	if (s1 && !s2)
		return (strdup(s1));
	if (!s1 && s2)
		return (strdup(s2));
	s1_len = strlen((char *)s1);
	s2_len = strlen(s2);
	stot_len = s1_len + s2_len + 1;
	rtn = malloc(sizeof(char) * stot_len);
	if (!rtn)
		return (0);
	memmove(rtn, s1, s1_len);
	memmove(rtn + s1_len, s2, s2_len);
	rtn[stot_len - 1] = '\0';
	return (rtn);
}*/

/*int main(void)
{
	char jr[] = "esto es una prueba";
	char as[] = " que continua asi";

	printf("este es el resultado de la union: %s\n", ft_strjoin(jr, as));
}*/