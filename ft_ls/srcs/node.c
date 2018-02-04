#include "ft_ls.h"

t_file	*new_file(char *name, char *path, struct stat *file_stat)
{
	t_file *new;

	new = (t_file *)ft_malloc(sizeof(t_file));
	new->name = name;
	new->path = path;
	new->stat = file_stat;
	return new;
}

void	free_file(void *void_file)
{
	t_file *file;

	file = (t_file *)void_file;
	if (file)
	{
		free(file->name);
		free(file->path);
		free(file->stat);
		free(file);
	}
}

void	read_dir(t_env *env, const char *path)
{
	DIR *dir;
	struct dirent *dirent;

	dir = opendir(path);
	if (dir)
	{
		while ((dirent = readdir(dir)) != NULL)
			read_file(env, dirent, path);
		if (errno == 0)
			closedir(dir);
		else
		{
			perror(NULL);
			exit(0);
		}
	}
	else
	{
		perror(NULL);
		exit(0);
	}
}

f_filecmp	get_compare(t_env *env)
{
	if (env->options->time == 1)
	{
		if (env->options->reverse == 1)
			return &r_time_filecmp;
		else
			return &time_filecmp;
	}
	else
	{
		if (env->options->reverse == 1)
			return &r_aplha_filecmp;
		else
			return &alpha_filecmp;
	}
}

void	read_file(t_env *env, struct dirent *dirent, const char *path)
{
	char		*name;
	char		*full_path;
	char		*tmp;

	name = ft_strdup(dirent->d_name);
	if (name[0] != '.' || env->options->hidden == 1)
	{
		tmp = ft_strjoin(path, "/");
		full_path = ft_strjoin(tmp, name);
		add_file_to_tree(env, full_path, name);
		free(tmp);
	}
}

void	print_file(void *void_file, void *void_env)
{
	t_file		*file;
	t_env		*env;
	char		buf[255];
	int			len;

	file = (t_file *)void_file;
	env = (t_env *)void_env;
	if (env->options->longer)
		print_stat(env, file->stat);
	if (S_ISLNK(file->stat->st_mode))
	{
		ft_putstr(file->name);
		ft_putstr(" -> ");
		if ((len = readlink(file->path, buf, 255)) < 0)
			perror(NULL);
		else
			write(1, buf, len);
		ft_putchar('\n');
	}
	else
		ft_putendl(file->name);
	if (env->options->recurse == 1 && S_ISDIR(file->stat->st_mode))
		add_file_to_tree(env, ft_strdup(file->path), ft_strdup(file->path));
}
