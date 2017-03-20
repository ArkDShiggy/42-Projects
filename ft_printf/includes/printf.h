/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:27:16 by jcatinea          #+#    #+#             */
/*   Updated: 2016/12/02 09:56:29 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include "printf_types.h"

int				ft_strinc(char *s, char c);
char			*ft_itoa_base(intmax_t value, t_options *options);
char			*ft_uitoa_base(uintmax_t value, t_options *options);
void			ft_putwchar(wchar_t value);
char			*wctos(wchar_t value);
char			*wstos(char *s1, wchar_t *s2, int len);
char			*adjust_prec(char *str, t_options *options, char flag);
char			*adjust_alt(char *str, t_options *options, char flag, int zero);
char			*add_sign(char *str, t_options *options);
char			*adjust_width(char *str, t_options *options);
int				conversion(char *s, size_t *i,
		va_list args, t_options *options);
int				percent_eval(char *s, size_t *i, va_list args);
int				eval_flags(char *s, size_t *i, t_options *options);
int				eval_width(char *s, size_t *i, t_options *options);
int				eval_precision(char *s, size_t *i, t_options *options);
void			adjust(char *str, t_options *options, int sign, int *len);
void			print_zeros(t_options *options, int *len);
void			print_white(t_options *options, int *len);
char			*get_prefix(t_options *options, int sign, char *str);
char			*get_sign(t_options *options, int sign);
void			error(char *s);
void			malloc_error(char *s);
int				ft_printf(const char *str, ...);
char			*xt_strdup(const char *s1);
char			*xt_strjoin(char const *s1, char const *s2);
char			*xt_strnew(size_t size);
char			*xt_strsub(char const *s, unsigned int start, size_t len);
char			*xt_itoa(intmax_t value, t_options *options, char *str);
char			*xt_uitoa_base(uintmax_t value, t_options *options, char *str);

#endif
