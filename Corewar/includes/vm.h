/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:05:34 by hmenzagh          #+#    #+#             */
/*   Updated: 2017/03/06 16:32:55 by cfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <unistd.h>
# include <term.h>
# include <limits.h>
# include "define.h"
# include "libft.h"

/*
** Structures :
*/

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_champion
{
	t_header			header;
	unsigned int		champ_real_uid;
	unsigned int		champ_uid;
	int					initial_pc;
	char				content[CHAMP_MAX_SIZE];
	int					live_count;
	ssize_t				last_live;
}					t_champion;

typedef struct		s_process
{
	struct s_process	*next;
	t_champion			*champion;
	ssize_t				pc;
	int					carry;
	int					reg[REG_NUMBER];
	int					instruction_cooldown;
	int					live;
	char				still_alive;
	char				need_fork;
	int					op;
}					t_process;

struct				s_temdata
{
	ssize_t				display_every;
	char				*termcap_ctl;
	char				*retclear;
	char				current_pause;
	struct termios		tattr;
	int					troll;
};

typedef struct		s_vm
{
	unsigned char		memory[MEM_SIZE];
	int					parent[MEM_SIZE];
	t_champion			champions[MAX_PLAYERS];
	int					champ_count;
	ssize_t				current_cycle;
	ssize_t				cycle_to_die;
	char				global_debug;
	t_process			*process;
	ssize_t				dump_at;
	int					termcaps;
	int					web;
	char				*web_filename;
	int					debug_champ;
	char				debug_color;
}					t_vm;

/*
** Parsing
*/

t_champion			get_champion(char *filename);
t_header			get_header(int fd);
void				get_content(int fd, char *content, unsigned int prog_size);
void				debug_champion(t_champion *champion);

typedef struct		s_op
{
	char						*name;
	int							arg_num;
	int							args[3];
	int							opcode;
	int							cycles;
	char						*info;
	int							coding_byte;
	int							label_size;
}					t_op;

/*
** Debug VM
*/

void				debug_vm(t_vm *db);
void				dump_memory(t_vm *db);
int					instruction(t_process *db, t_vm *vm);
void				cycle_live(t_vm *vm);
int					process_len(t_process *process);
void				end_print(t_vm *vm);

#endif
