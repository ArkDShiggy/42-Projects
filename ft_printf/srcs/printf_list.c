/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:00:50 by jcatinea          #+#    #+#             */
/*   Updated: 2016/11/28 13:12:32 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		list_part_one(t_fun_types *list, int *count)
{
	list[(*count)++] = (t_fun_types){"d", &print_d};
	list[(*count)++] = (t_fun_types){"i", &print_d};
	list[(*count)++] = (t_fun_types){"ld", &print_ld};
	list[(*count)++] = (t_fun_types){"li", &print_ld};
	list[(*count)++] = (t_fun_types){"D", &print_ld};
	list[(*count)++] = (t_fun_types){"I", &print_ld};
	list[(*count)++] = (t_fun_types){"lli", &print_lld};
	list[(*count)++] = (t_fun_types){"lld", &print_lld};
	list[(*count)++] = (t_fun_types){"hd", &print_hd};
	list[(*count)++] = (t_fun_types){"hi", &print_hd};
	list[(*count)++] = (t_fun_types){"hhd", &print_hhd};
	list[(*count)++] = (t_fun_types){"hhi", &print_hhd};
	list[(*count)++] = (t_fun_types){"ji", &print_jd};
	list[(*count)++] = (t_fun_types){"jd", &print_jd};
	list[(*count)++] = (t_fun_types){"zi", &print_zd};
	list[(*count)++] = (t_fun_types){"zd", &print_zd};
	list[(*count)++] = (t_fun_types){"p", &print_p};
	list[(*count)++] = (t_fun_types){"%", &print_c};
}

void		list_part_four(t_fun_types *list, int *count)
{
	list[(*count)++] = (t_fun_types){"lD", &print_ld};
	list[(*count)++] = (t_fun_types){"lI", &print_ld};
	list[(*count)++] = (t_fun_types){"llI", &print_lld};
	list[(*count)++] = (t_fun_types){"llD", &print_lld};
	list[(*count)++] = (t_fun_types){"hD", &print_hd};
	list[(*count)++] = (t_fun_types){"hI", &print_hd};
	list[(*count)++] = (t_fun_types){"hhD", &print_hhd};
	list[(*count)++] = (t_fun_types){"hhI", &print_hhd};
	list[(*count)++] = (t_fun_types){"jI", &print_jd};
	list[(*count)++] = (t_fun_types){"jD", &print_jd};
	list[(*count)++] = (t_fun_types){"zI", &print_zd};
	list[(*count)++] = (t_fun_types){"zD", &print_zd};
	list[(*count)++] = (t_fun_types){"lO", &print_lu};
	list[(*count)++] = (t_fun_types){"lU", &print_lu};
	list[(*count)++] = (t_fun_types){"llO", &print_llu};
	list[(*count)++] = (t_fun_types){"llU", &print_llu};
	list[(*count)++] = (t_fun_types){"hO", &print_lu};
	list[(*count)++] = (t_fun_types){"hU", &print_lu};
	list[(*count)++] = (t_fun_types){"hhO", &print_hhu};
	list[(*count)++] = (t_fun_types){"hhU", &print_hhu};
	list[(*count)++] = (t_fun_types){"jO", &print_ju};
	list[(*count)++] = (t_fun_types){"jU", &print_ju};
	list[(*count)++] = (t_fun_types){"zO", &print_zu};
	list[(*count)++] = (t_fun_types){"zU", &print_zu};
}

void		list_part_two(t_fun_types *list, int *count)
{
	list[(*count)++] = (t_fun_types){"u", &print_u};
	list[(*count)++] = (t_fun_types){"o", &print_u};
	list[(*count)++] = (t_fun_types){"lu", &print_lu};
	list[(*count)++] = (t_fun_types){"lo", &print_lu};
	list[(*count)++] = (t_fun_types){"U", &print_lu};
	list[(*count)++] = (t_fun_types){"O", &print_lu};
	list[(*count)++] = (t_fun_types){"llo", &print_llu};
	list[(*count)++] = (t_fun_types){"llu", &print_llu};
	list[(*count)++] = (t_fun_types){"hu", &print_hu};
	list[(*count)++] = (t_fun_types){"ho", &print_hu};
	list[(*count)++] = (t_fun_types){"hhu", &print_hhu};
	list[(*count)++] = (t_fun_types){"hho", &print_hhu};
	list[(*count)++] = (t_fun_types){"jo", &print_ju};
	list[(*count)++] = (t_fun_types){"ju", &print_ju};
	list[(*count)++] = (t_fun_types){"zo", &print_zu};
	list[(*count)++] = (t_fun_types){"zu", &print_zu};
}

void		list_part_three(t_fun_types *list, int *count)
{
	list[(*count)++] = (t_fun_types){"x", &print_u};
	list[(*count)++] = (t_fun_types){"X", &print_u};
	list[(*count)++] = (t_fun_types){"lx", &print_lu};
	list[(*count)++] = (t_fun_types){"lX", &print_lu};
	list[(*count)++] = (t_fun_types){"llX", &print_llu};
	list[(*count)++] = (t_fun_types){"llx", &print_llu};
	list[(*count)++] = (t_fun_types){"hx", &print_hu};
	list[(*count)++] = (t_fun_types){"hX", &print_hu};
	list[(*count)++] = (t_fun_types){"hhx", &print_hhu};
	list[(*count)++] = (t_fun_types){"hhX", &print_hhu};
	list[(*count)++] = (t_fun_types){"jX", &print_ju};
	list[(*count)++] = (t_fun_types){"jx", &print_ju};
	list[(*count)++] = (t_fun_types){"zX", &print_zu};
	list[(*count)++] = (t_fun_types){"zx", &print_zu};
	list[(*count)++] = (t_fun_types){"c", &print_c};
	list[(*count)++] = (t_fun_types){"s", &print_s};
	list[(*count)++] = (t_fun_types){"C", &print_lc};
	list[(*count)++] = (t_fun_types){"S", &print_ls};
	list[(*count)++] = (t_fun_types){"lc", &print_lc};
	list[(*count)++] = (t_fun_types){"ls", &print_ls};
}

int			type_list(char *flags, t_options *options, va_list args)
{
	int			count;
	int			j;
	t_fun_types list[100];

	count = 0;
	list_part_one(list, &count);
	list_part_two(list, &count);
	list_part_three(list, &count);
	list_part_four(list, &count);
	list[count] = (t_fun_types){0, 0};
	j = 0;
	while (list[j].flags)
	{
		if (ft_strequ(list[j].flags, flags))
			return (*(list[j].function))(options, args);
		j++;
	}
	return (-1);
}
