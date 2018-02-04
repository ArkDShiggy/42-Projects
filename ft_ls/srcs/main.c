#include "ft_ls.h"

void	activate_option(t_options *options, char *arg)
{
	int j;
	char c;

	j = 0;
	while (arg[j] != '\0')
	{
		c = arg[j];
		if (c == 'a')
			options->hidden = 1;
		else if (c == 'r')
		 	options->reverse = 1;
		else if (c == 't')
			options->time = 1;
		else if (c == 'R')
			options->recurse = 1;
		else if (c == 'l')
			options->longer = 1;
		j++;
	}
}

void	add_file_to_tree(t_env *env, char *path, char *name)
{
	t_file		*file;
	t_btree		*new;
	struct stat	*file_stat;

	file_stat = (struct stat *)ft_malloc(sizeof(struct stat));
	lstat(path, file_stat);
	env_update(env, file_stat);
	file = new_file(name, path, file_stat);
	new = new_btree(file);
	btree_add(&env->root, new, get_compare(env));
}

void	parse_args(int argc, char **argv, t_env *env)
{
	int			i;
	int			j;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		activate_option(env->options, argv[i]);
		i++;
	}
	j = 0;
	while ((i + j) < argc)
	{
		add_file_to_tree(env, ft_strdup(argv[i + j]), ft_strdup(argv[i + j]));
		j++;
	}
	if (j == 0)
		add_file_to_tree(env, ft_strdup("."), ft_strdup("."));
	if (j > 1)
		env->start = 1;
}
/*
void	add_to_queue(void *void_file, void *void_queue)
{
	t_queue	**queue;
	t_file	*file;

	file = (t_file *)void_file;
	queue = (t_queue **)void_queue;
	queue_push(queue, file);
}
*/
void pass() {}

void	ft_ls_two(void *void_file, void *void_env)
{
	t_file	*file;
	t_env	*old_dir_env;
	t_env	*file_env;
	t_env	*new_dir_env;

	file = (t_file *)void_file;
	old_dir_env = (t_env *)void_env;
	file_env = copy_env(old_dir_env);
	read_dir(file_env, file->path);
	if (old_dir_env->start == 2)
		ft_putstr("\n");
	if (old_dir_env->start > 0)
	{
		ft_putstr(file->path);
		ft_putstr(":\n");
	}
	old_dir_env->start = 2;
	if (old_dir_env->options->longer == 1)
	{
		ft_putstr("total ");
		ft_putendl(ft_itoa(file_env->blocks));
	}
	if (file_env->options->recurse == 1)
	{
		new_dir_env = copy_env(file_env);
		btree_map_one(file_env->root, &print_file, new_dir_env);
		reset_env(new_dir_env);
		btree_map_one(new_dir_env->root, &ft_ls_two, new_dir_env);
		free_env(new_dir_env);
	}
	else
		btree_map_one(file_env->root, &print_file, file_env);
	free_env(file_env);
}

/*
void	ft_ls(t_env *env)
{
	int		i;
	t_file	*file;
	t_env	*new_env;

	btree_map_one(env->root, &add_to_queue, env->queue);
	btree_free(env->root, &pass);
	env->root = NULL;
	i = 0;
	while (*(env->queue) != NULL)
	{
		file = (t_file *)(queue_pop(env->queue));
		read_dir(env, file->path);
		if (i > 0 || env->copy == 1)
			ft_putstr("\n");
		if (i > 0 || (i == 0 && *(env->queue) != NULL) || env->copy == 1)
		{
			ft_putstr(file->path);
			ft_putstr(":\n");
		}
		free_file(file);
		new_env = copy_env(env);
		btree_map_one(env->root, &print_file, new_env);
		if (env->options->recurse == 1)
			ft_ls(new_env);
		btree_free(env->root, &free_file);
		env->root = NULL;
		i++;
	}
	free_env(env);
}
*/
int		main(int argc, char **argv)
{
	t_env	*env;

	env = init_env();
	parse_args(argc, argv, env);
	btree_map_one(env->root, &ft_ls_two, env);
	free_env(env);
}
