/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:13:02 by msakwins          #+#    #+#             */
/*   Updated: 2016/12/27 20:36:51 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_char(char *str, int i, int j, int k)
{
	if (!str[i])
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (1);
		if (str[i] == '\n' && (str[i - 1] == '.' || str[i - 1] == '#'))
			j++;
		if (((str[i] == '\n' && str[i + 1] == '\n') && (str[i - 1] == '.'
			|| str[i - 1] == '#')) && (j != 4 * (k + 1)))
			return (1);
		if (str[i] == '\n' && str[i - 1] == '\n' && str[i + 1] != '\n'
			&& str[i + 1] != '\0')
			k++;
		i++;
	}
	if ((i - j) != (4 * j + k) || (j != 4 * (k + 1)))
		return (1);
	return (0);
}

int		ft_check_place(char *str, int i, int j)
{
	int		count;

	while (str[i] && (j = 0))
	{
		while (j != 4 && (count = 0))
		{
			while (count++ != 3)
				if (str[i++] == '\n')
					return (1);
			if (str[i++] == '\n')
				j++;
			else if (str[i] == '\0')
				return (1);
			else
				return (1);
			i++;
		}
		if (str[i] == '\n')
			i++;
		else if (str[i] == '\0')
			return (0);
		else
			return (1);
	}
	return (0);
}

int		ft_check_size(char *str)
{
	int		ret;

	ret = ft_check_place(str, 0, 0);
	return (ret);
}
