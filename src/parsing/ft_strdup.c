#include "parsing.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
