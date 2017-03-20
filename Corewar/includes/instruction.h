/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfabre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:09:22 by cfabre            #+#    #+#             */
/*   Updated: 2017/03/06 16:30:47 by cfabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_H
# define INSTRUCTION_H
# define CARRY(x) (x==0)? 1 : 0
# include "corelib.h"

typedef int	(*t_instruction)(t_process *db, t_vm *vm);

int			op_lfork(t_process *dbi, t_vm *vm);
int			op_sti(t_process *db, t_vm *vm);
int			op_fork(t_process *db, t_vm *vm);
int			op_lld(t_process *db, t_vm *vm);
int			op_ld(t_process *db, t_vm *vm);
int			op_add(t_process *db, t_vm *vm);
int			op_zjmp(t_process *db, t_vm *vm);
int			op_sub(t_process *db, t_vm *vm);
int			op_ldi(t_process *db, t_vm *vm);
int			op_or(t_process *db, t_vm *vm);
int			op_st(t_process *db, t_vm *vm);
int			op_aff(t_process *db, t_vm *vm);
int			op_live(t_process *db, t_vm *vm);
int			op_xor(t_process *db, t_vm *vm);
int			op_lldi(t_process *db, t_vm *vm);
int			op_and(t_process *db, t_vm *vm);
int			op_no(t_process *db, t_vm *vm);

/*
** recuperation des parametre.
*/

int			first_param(unsigned char in);
int			second_param(unsigned char in);
int			last_param(unsigned char in);

#endif
