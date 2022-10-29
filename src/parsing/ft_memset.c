#include "cub3d.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) b;
	while (len > 0)
	{
		(*ptr++) = (unsigned char) c;
		len--;
	}
	return (b);
}