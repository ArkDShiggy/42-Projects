/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcatinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 12:38:48 by jcatinea          #+#    #+#             */
/*   Updated: 2017/06/04 12:38:54 by jcatinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		read_line(char *line)
{
    int j;
    int count;
    int num_flag;

    j = 0;
    num_flag = 1;
    count = 1;
    while (line[j])
    {
        if (line[j] == ' ')
        {
            if (num_flag == 1)
                error("Wrong file format: unexpected whitespace");
			else
            {
                num_flag = 1;
                count += 1;
            }
        }
        else
            num_flag = 0;
        j++;
    }
    return (count);
}

void	get_dimensions(int fd, t_data *data)
{
    int		i;
    char	*line;
    int		count;

    i = 0;
	ft_putstr("dim\n");
    while (get_next_line(fd, &line) == 1)
    {
        count = read_line(line);
        if (i == 0)
            data->width = count;
        else
        {
            if (data->width != count)
                error("Wrong file format: one line has not the correct number of values");
        }
		free(line);
        i++;
    }
    data->height = i;
}

void	read_data(int fd, t_data *data)
{
    int		i;
    int		j;
    int		str_index;
    char	*line;

    i = 0;
    while (i < data->height)
    {
        j = 0;
        str_index = 0;
        get_next_line(fd, &line);
        while (line[str_index])
        {
            if (ft_isdigit(line[str_index]) || line[str_index] == '-')
            {
                data->data[i * data->width + j] = ft_atoi(line + str_index);
                j += 1;
				str_index += 1;
                while (ft_isdigit(line[str_index]))
                    str_index += 1;
            }
            else if (line[str_index] == ' ')
                str_index += 1;
            else
                error("Wrong file format: unexpected character");
		}
		free(line);
        i++;
    }
}

t_data	*get_data_from_file(char *filename)
{
    int		fd;
    t_data	*data;

    fd = open(filename, O_RDONLY);
	if (fd < 0)
		error("Can't open file\n");
    data = (t_data *)ft_malloc(sizeof(t_data));
    get_dimensions(fd, data);
    close(fd);
	ft_putnbr(data->width * data->height);
    data->data = (int *)ft_malloc(sizeof(int) * (data->width * data->height));
    fd = open(filename, O_RDONLY);
    read_data(fd, data);
	close(fd);
    return (data);
}
