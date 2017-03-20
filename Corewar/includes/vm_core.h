/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_core.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:34:09 by hmenzagh          #+#    #+#             */
/*   Updated: 2017/03/06 16:34:26 by cfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_CORE_H
# define VM_CORE_H

# include "vm.h"

/*
** Structures :
*/
typedef struct		s_args
{
	int				uids[MAX_PLAYERS];
	char			*file_name[MAX_PLAYERS];
	int				dump;
	int				web;
	char			*web_filename;
	int				termcaps;
	int				debug_champ;
	int				champ_count;
}					t_args;

typedef struct		s_types
{
	int				types[3];
	int				i;
	int				or_pc;
}					t_types;

typedef struct		s_res
{
	int				ret_value;
	int				or_pc;
	int				val[3];
	int				or_val[3];
	int				types[3];
}					t_res;

typedef struct		s_web
{
	int				to_print;
	int				id;
	int				parent;
	int				value;
}					t_web;
/*
** Structures fcts :
*/
t_vm				*init_vm_struct(void);
void				load_champs(t_vm *vm, t_args *args);
void				setup_memory(t_vm *vm);
/*
** Parse fcts :
*/
t_args				parse_args(int ac, char **av);
intmax_t			ft_secure_atoi(const char *str);
void				setup_uids(t_args *args);
/*
** Process fcts
*/
t_process			*create_process(t_champion *champ);
void				add_process(t_process **origin, t_process *new);
void				fork_process(t_process *process, int pc);
void				delete_process(t_process **process);
void				gen_process_list(t_vm *vm);
/*
** debug
*/
void				debug_vm_champs(t_vm *vm);
void				debug_process(t_vm *vm);
/*
** Free
*/
void				free_all(t_vm *vm);
/*
** Web
*/
int					create_file(t_vm *vm);
void				web_output(char *s, int fd);
void				close_file(int fd);
int					web_output_memory_return_fd(t_vm *vm);
void				web_output_memory_case(t_vm *vm, int id, int command);
void				start_cycle_web(t_vm *vm, t_process *process);
void				end_cycle_web(int command, int fd);
/*
** Additionnal :
*/
void				cycle_live_end(t_vm *vm, struct s_temdata *td);
void				cycle_live_post(t_vm *vm, struct s_temdata *td);
void				cycle_live_pre(t_vm *vm);

#endif
