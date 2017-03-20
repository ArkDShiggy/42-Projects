/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corelib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 11:32:26 by hmenzagh          #+#    #+#             */
/*   Updated: 2017/03/06 17:58:32 by hmenzagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORELIB_H
# define CORELIB_H

# include "vm.h"
# include "vm_core.h"

ssize_t			get_pc(t_process *db);
void			set_pc(t_process *db, ssize_t val);

int				get_carry(t_process *db);
void			change_carry(t_process *db, unsigned int carry);

void			set_reg(t_process *db, ssize_t reg_id, int val);
int				get_reg(t_process *db, ssize_t reg_id);

char			get_ind(ssize_t pc_off, t_vm *vm);
void			set_ind(ssize_t pc_off, t_vm *vm, char val, int parent);

ssize_t			get_ind_of(ssize_t pc_offset, t_vm *vm, int size);
void			set_ind_of(ssize_t pc_offset, t_vm *vm, int val[2], int parent);

int				decode_info(unsigned char c, int para);

void			ft_magic_params(t_process *process, t_vm *vm, t_res *res);

int				ini_termcap(struct s_temdata *td, int enable);
void			termdisp(struct s_temdata *td, t_vm *vm);
void			reset_term(struct s_temdata *td);

void			pay_song(char *name);

int				rtf_uid(unsigned int real, t_vm *vm);

#endif
