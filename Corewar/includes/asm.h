/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:15:25 by jcatinea          #+#    #+#             */
/*   Updated: 2017/03/09 11:08:02 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "get_next_line.h"
# include "define.h"
# include "vm.h"
# include "fcntl.h"

typedef struct	s_name_comment
{
	char		*dest;
	int			length;
}				t_nc;

typedef struct	s_label
{
	int			byte;
	char		*name;
}				t_label;

typedef struct	s_arg
{
	int			code;
	int			numeric;
	char		*label;
	int			value;
}				t_arg;

typedef struct	s_command
{
	t_op		op;
	int			code;
	t_arg		args[3];
}				t_command;

typedef struct	s_env
{
	t_header	*header;
	t_list		**to_write;
	t_list		**defined_labels;
	t_list		**used_labels;
}				t_env;

typedef struct	s_position
{
	int			line;
	int			col;
	int			byte;
}				t_position;

t_op			get_op_from_name(char *name);
t_nc			*get_nc(t_header *header, int a);

void			verify_env(t_env *env);
void			free_env(t_env *env);

int				ft_strinc(char a, char *str);
int				is_whitespace(char a);
void			skip_comment(char *str);
int				skip_whitespace(char *str, t_position *pos);
void			check_endline(char *str, t_position *pos);
int				line_content(char *str);
void			ft_lstappend(t_list **alst, t_list *new);

void			read_file(int fd, t_env *env);
void			read_file_two(int fd, t_position *pos, t_env *env);

void			parse_line(char *str, t_position *pos, t_env *env);
int				is_label(char *str, t_position *pos);
void			check_label(char *str, t_position *pos, t_env *env);
void			check_instruction(char *str, t_position *pos,
	t_command *command);

void			check_arguments(char *str, t_position *pos, t_env *env,
	t_command *command);

void			read_header_str(char *str, t_position *pos, int fd, t_nc *dest);
int				read_header_str_two(char *str, t_position *pos, int fd,
	t_nc *new);
void			read_header_new_line(t_position *pos, int *i, t_nc *new);
int				get_header_str(t_header *header, char *str,
	t_position *pos, int fd);
t_header		*read_header(int fd, t_position *pos);

void			error(char *str);
void			parse_error(char *str, t_position *pos);
void			show_usage(void);

void			write_header(int fd, t_header *header);
void			write_file(int fd2, t_env *env);

t_env			*new_env(void);
void			add_used_label(t_env *env, char *name);
void			add_defined_label(t_env *env, char *name, int byte);
int				label_exists(t_env *env, char *name);

t_arg			*get_arg(char *str, t_position *pos, t_env *env);
int				label_to_value(char *name, t_list **list);
void			free_env(t_env *env);
intmax_t		ft_secure_atoi(const char *str);

#endif
