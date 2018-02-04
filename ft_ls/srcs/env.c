#include "ft_ls.h"

t_options *init_options()
{
	t_options	*options;

	options = (t_options *)ft_malloc(sizeof(t_options));
	options->hidden = 0;
	options->reverse = 0;
	options->time = 0;
	options->recurse = 0;
	options->longer = 0;
	return options;
}

t_env	*init_env()
{
	t_env *env;

	env = (t_env *)ft_malloc(sizeof(t_env));
	env->options = init_options();
	env->root = NULL;
	env->blocks = 0;
	env->user_length = 0;
	env->group_length = 0;
	env->size_length = 0;
	env->link_length = 0;
	env->start = 0;
	return env;
}

t_env	*copy_env(t_env *env)
{
	t_env *new;

	new = init_env();
	new->options->hidden = env->options->hidden;
	new->options->reverse = env->options->reverse;
	new->options->time = env->options->time;
	new->options->recurse = env->options->recurse;
	new->options->longer = env->options->longer;
	new->start = 2;
	return new;
}

void	free_env(t_env *env)
{
	free(env->options);
	env->options = NULL;
	btree_free(env->root, &free_file);
	free(env);
	env = NULL;
}

void	reset_env(t_env *env)
{
	env->blocks = 0;
	env->user_length = 0;
	env->group_length = 0;
	env->size_length = 0;
	env->link_length = 0;
}
