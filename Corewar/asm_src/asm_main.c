/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 11:19:28 by jcatinea          #+#    #+#             */
/*   Updated: 2017/03/06 16:19:18 by cfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_filename(char *arg)
{
	int		len;
	int		i;
	char	*new;

	len = ft_strlen(arg);
	new = NULL;
	if (arg[len - 1] == 's' && arg[len - 2] == '.')
	{
		i = 0;
		new = (char *)ft_memalloc(sizeof(char) * (len + 3));
		while (i < len)
		{
			new[i] = arg[i];
			i++;
		}
		new[len - 1] = 'c';
		new[len] = 'o';
		new[len + 1] = 'r';
		new[len + 2] = '\0';
	}
	else
		error("File is not a .s file");
	return (new);
}

void	read_file(int fd, t_env *env)
{
	t_position		*pos;

	pos = (t_position *)ft_memalloc(sizeof(t_position));
	pos->line = 1;
	pos->col = 1;
	pos->byte = 0;
	env->header = read_header(fd, pos);
	read_file_two(fd, pos, env);
	(env->header)->prog_size = pos->byte;
	free(pos);
	verify_env(env);
}

void	verify_env(t_env *env)
{
	t_list	*node;
	t_label	*label;

	node = *(env->used_labels);
	while (node)
	{
		label = (t_label *)(node->content);
		if (label_exists(env, label->name) == 0)
		{
			ft_putstr_fd("Error: The following label ", 2);
			ft_putstr_fd(label->name, 2);
			ft_putendl_fd("is used but not defined", 2);
		}
		node = node->next;
	}
}

void	read_file_two(int fd, t_position *pos, t_env *env)
{
	char *str;

	while (get_next_line(fd, &str) > 0)
	{
		skip_comment(str);
		if (line_content(str) == 1)
			parse_line(str, pos, env);
		(pos->line)++;
		pos->col = 1;
		free(str);
	}
}

int		main(int argc, char **argv)
{
	char		*filename;
	int			fd1;
	int			fd2;
	t_env		*env;

	if (argc != 2)
		show_usage();
	else
	{
		env = new_env();
		filename = get_filename(argv[1]);
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 <= 0)
			error("Can't open the file");
		read_file(fd1, env);
		close(fd1);
		fd2 = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		free(filename);
		if (fd2 <= 0)
			error("Can't create the file");
		write_file(fd2, env);
		close(fd2);
		free_env(env);
	}
	return (0);
}
