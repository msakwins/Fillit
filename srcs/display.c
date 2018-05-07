/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:52:39 by bbeldame          #+#    #+#             */
/*   Updated: 2016/12/27 19:47:29 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**emptysquare(int size)
{
	char	**str;
	int		i;
	int		j;

	if (size == 0)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(str[i] = (char *)malloc(sizeof(char) * (size + 2))))
			return (NULL);
		j = 0;
		while (j < size)
			str[i][j++] = '.';
		str[i][j++] = '\n';
		str[i][j] = '\0';
		i++;
	}
	str[i] = NULL;
	return (str);
}

void			display(t_square *lilsq)
{
	char	**str;
	int		i;
	t_mino	*tmp;
	t_mino	*tmp2;

	i = 0;
	str = emptysquare(lilsq->size);
	if (str)
	{
		while (lilsq->content[i])
		{
			tmp = lilsq->content[i]->fst;
			while (tmp)
			{
				tmp2 = tmp->next;
				str[tmp->posy][tmp->posx] = 'A' + lilsq->content[i]->place;
				tmp = tmp2;
			}
			i++;
		}
		i = 0;
		while (str[i])
			ft_putstr(str[i++]);
	}
}
