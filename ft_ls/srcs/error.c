#include "ft_ls.h"

void	*ft_malloc(size_t size)
{
	void *new;
	if ((new = malloc(size)) == NULL)
	{
		exit(0);
	}
	return new;
}
