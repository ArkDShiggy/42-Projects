#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include "libft.h"
# include "btree.h"
# include "queue.h"

typedef struct	s_options
{
	char		hidden;
	char		reverse;
	char		time;
	char		recurse;
	char		longer;
}				t_options;

typedef struct	s_file
{
	char		*name;
	char		*path;
	struct stat	*stat;
}				t_file;

typedef struct	s_env
{
	t_options	*options;
	t_btree		*root;
	int			blocks;
	int			group_length;
	int			user_length;
	int			size_length;
	int			link_length;
	int			start;
}				t_env;

typedef int (*f_filecmp)(void *, void *);

void			*ft_malloc(size_t size);
void			activate_option(t_options *options, char *arg);
void			parse_args(int argc, char **argv, t_env *env);
t_options		*init_options();
t_env			*init_env();
t_env			*copy_env(t_env *env);
void			free_env(t_env *env);
void			reset_env(t_env *env);
t_file			*new_file(char *name, char *path, struct stat *);
void			free_file(void *void_file);
void			read_dir(t_env *env, const char *path);
f_filecmp		get_compare(t_env *env);
void			read_file(t_env *env, struct dirent *dirent, const char *path);
void			print_file(void *file, void *env);
void			add_file_to_tree(t_env *env, char *path, char *name);
int				alpha_filecmp(void *a, void *b);
int				r_aplha_filecmp(void *a, void *b);
int				time_filecmp(void *a, void *b);
int				r_time_filecmp(void *a, void *b);
void			env_update(t_env* env, struct stat *file_stat);
void			putstr_rpad(char *str, int size);
void			putstr_lpad(char *str, int size);
void			print_stat(t_env *env, struct stat *file_stat);
char			*block_str(struct stat *file_stat);

#endif
