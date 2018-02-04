#include "ft_ls.h"

int	alpha_filecmp(void *a, void *b)
{
	return ft_strcmp(((t_file *)a)->name, ((t_file *)b)->name);
}

int r_aplha_filecmp(void *a, void *b)
{
	return (-1 * alpha_filecmp(a, b));
}

int time_filecmp(void *a, void *b)
{
	return (((t_file *)b)->stat->st_mtime - ((t_file *)a)->stat->st_mtime);
}

int r_time_filecmp(void *a, void *b)
{
	return (-1 * time_filecmp(a, b));
}
