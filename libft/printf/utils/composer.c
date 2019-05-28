/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   composer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-ru <rle-ru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:39:06 by rle-ru            #+#    #+#             */
/*   Updated: 2019/05/28 06:04:23 by rle-ru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_translater	*create_table(void)
{
	t_translater	*table;

	table = (t_translater *)ft_memalloc(sizeof(t_translater) * 20);
	table[0] = (t_translater){'s', &str_to_str};
	table[1] = (t_translater){'i', &int_to_str};
	table[2] = (t_translater){'d', &int_to_str};
	table[3] = (t_translater){'c', &char_to_str};
	table[4] = (t_translater){'e', &distribute_floats};
	table[5] = (t_translater){'E', &distribute_floats};
	table[6] = (t_translater){'g', &distribute_floats};
	table[7] = (t_translater){'G', &distribute_floats};
	table[8] = (t_translater){'f', &distribute_floats};
	table[9] = (t_translater){'%', &mod_to_str};
	table[10] = (t_translater){'u', &uint_to_str};
	table[11] = (t_translater){'x', &x_to_str};
	table[12] = (t_translater){'X', &xu_to_str};
	table[13] = (t_translater){'o', &o_to_str};
	table[14] = (t_translater){'b', &b_to_str};
	table[15] = (t_translater){'p', &p_to_str};
	table[16] = (t_translater){'D', &int_to_str};
	table[17] = (t_translater){'O', &o_to_str};
	table[18] = (t_translater){'U', &uint_to_str};
	table[19] = (t_translater){0, NULL};
	return (table);
}

static int		finder(char id, t_translater *table)
{
	int		i;

	i = 0;
	while (table[i].type)
	{
		if (table[i].type == id)
			return (i);
		i++;
	}
	return (-1);
}

void			compute_infos(
	t_info *info, t_translater *table, va_list *args, char **output)
{
	info->result =
		table[finder(info->specifier, table)].f(args, info);
	set_to_precision(info);
	set_zero_width(info);
	set_flags(info);
	set_width(info);
	*output = ft_strjoin_free(*output, info->result, LEFT + RIGHT);
}

char			*record_string(char *format, va_list *args, t_translater *table)
{
	int				next;
	t_info			*info;
	char			*output;
	int				find;

	find = 0;
	output = ft_strnew(0);
	while ((next = next_identifier(format)) >= 0)
	{
		info = parser(&format[next], args);
		output = ft_strnjoin(output, format, next);
		if ((find = finder(info->specifier, table)) == -1)
		{
			format += next + 1;
			free(info);
			continue;
		}
		compute_infos(info, table, args, &output);
		format += next + info->size;
		free(info);
	}
	output = ft_strjoin_free(output, format, LEFT);
	return (output);
}
