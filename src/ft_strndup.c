
#include "cub3d.h"

char	*ft_strndup(char *s, int n)
{
	char	*dup;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
