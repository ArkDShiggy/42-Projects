/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:50:36 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/02 13:59:06 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_TYPES_H
# define PRINTF_TYPES_H

typedef struct	s_options
{
	int			width;
	int			precision;
	char		sign;
	char		fill;
	char		alt;
	char		flag;
}				t_options;

typedef struct	s_fun_types
{
	char		*flags;
	int			(*function)(t_options *, va_list);
}				t_fun_types;

int				type_list(char *flags, t_options *options, va_list args);
int				print_d(t_options *options, va_list args);
int				print_ld(t_options *options, va_list args);
int				print_lld(t_options *options, va_list args);
int				print_hd(t_options *options, va_list args);
int				print_hhd(t_options *options, va_list args);
int				print_jd(t_options *options, va_list args);
int				print_zd(t_options *options, va_list args);
int				print_u(t_options *options, va_list args);
int				print_lu(t_options *options, va_list args);
int				print_llu(t_options *options, va_list args);
int				print_hu(t_options *options, va_list args);
int				print_hhu(t_options *options, va_list args);
int				print_ju(t_options *options, va_list args);
int				print_zu(t_options *options, va_list args);
int				print_c(t_options *options, va_list args);
int				print_s(t_options *options, va_list args);
int				print_lc(t_options *options, va_list args);
int				print_ls(t_options *options, va_list args);
int				print_p(t_options *options, va_list args);
int				print_zero_chars(t_options *options);

#endif
