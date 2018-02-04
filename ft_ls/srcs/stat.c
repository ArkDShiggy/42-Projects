#include "ft_ls.h"

void	env_update(t_env* env, struct stat *file_stat)
{
	char	*str;
	int		len;

	env->blocks += (int)(file_stat->st_blocks);
	len = ft_strlen(getpwuid(file_stat->st_uid)->pw_name);
	if (len > env->user_length)
		env->user_length = len;
	len = ft_strlen(getgrgid(file_stat->st_gid)->gr_name);
	if (len > env->group_length)
		env->group_length = len;
	str = block_str(file_stat);
	len = ft_strlen(str);
	free(str);
	if (len > env->size_length)
		env->size_length = len;
	str = ft_itoa((int)(file_stat->st_nlink));
	len = ft_strlen(str);
	free(str);
	if (len > env->link_length)
		env->link_length = len;
}

void	putstr_rpad(char *str, int size)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
	while (i < size)
	{
		ft_putchar(' ');
		i++;
	}
}

void	putstr_lpad(char *str, int size)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = 0;
	while (i < size - len)
	{
		ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_permissions(mode_t val)
{
	if (S_ISREG(val))
		ft_putchar('-');
	if (S_ISDIR(val))
		ft_putchar('d');
	if (S_ISBLK(val))
		ft_putchar('b');
	if (S_ISCHR(val))
		ft_putchar('c');
	if (S_ISFIFO(val))
		ft_putchar('p');
	if (S_ISLNK(val))
		ft_putchar('l');
	if (S_ISSOCK(val))
		ft_putchar('s');
	(val & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
    (val & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
    (val & S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
    (val & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
    (val & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
    (val & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
    (val & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
    (val & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
    (val & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
}

char	*block_str(struct stat *file_stat)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	int		a;
	int		b;

	if (S_ISCHR(file_stat->st_mode) || S_ISBLK(file_stat->st_mode))
	{
		a = file_stat->st_rdev / 0x1000000;
		b = file_stat->st_rdev % 0x1000000;
		tmp = ft_itoa(a);
		tmp2 = ft_strjoin(tmp, ", ");
		free(tmp);
		tmp = ft_itoa(b);
		str = ft_strjoin(tmp2, tmp);
		free(tmp);
		free(tmp2);
	}
	else
		str = ft_itoa((int)(file_stat->st_size));
	return str;
}

void	print_stat(t_env *env, struct stat *file_stat)
{
	char *str;

	print_permissions(file_stat->st_mode);
	str = ft_itoa((int)(file_stat->st_nlink));
	ft_putchar(' ');
	putstr_lpad(str, env->link_length + 1);
	free(str);
	ft_putchar(' ');
	putstr_rpad(getpwuid(file_stat->st_uid)->pw_name, env->user_length + 2);
	putstr_rpad(getgrgid(file_stat->st_gid)->gr_name, env->group_length + 1);
	str = block_str(file_stat);
	putstr_lpad(str, env->size_length + 1);
	free(str);
	ft_putchar(' ');
	str = ft_strsub(ctime(&file_stat->st_mtime), 4, 12);
	ft_putstr(str);
	ft_putchar(' ');
	free(str);
}
