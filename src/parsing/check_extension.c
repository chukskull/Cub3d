#include "parsing.h"

int	check_extension(char *src, char *to_find)
{
	int		i;
	size_t	j;

	i = 0;
	printf("%p and %p\n", src, to_find);
	j = ft_strlen(src) - ft_strlen(to_find);
	while ((src[j] && to_find[i])
		&& (src[j++] == to_find[i++]))
		;
	if (j == ft_strlen(src))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
