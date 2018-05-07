/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:13:22 by bbeldame          #+#    #+#             */
/*   Updated: 2016/12/27 20:01:41 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				touchiall(t_square *parsed)
{
	int i;

	i = 1;
	while (parsed->content[i])
		if (touchi(parsed, parsed->content[i++]))
			return (1);
	return (0);
}

int				count_mino(t_square *sq)
{
	int i;

	i = 0;
	while (sq->content[i])
		i++;
	return (i);
}

int				biggerthansize(t_mino *first, int size)
{
	t_mino	*temp;

	temp = first;
	while (temp)
	{
		if (temp->posx >= size - 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int				canmove(t_mino *fst, int size)
{
	t_mino *tmp;

	tmp = fst;
	while (tmp)
	{
		if (tmp->posy >= size - 1)
		{
			if (biggerthansize(fst, size))
			{
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

int				touchi(t_square *parsed, t_tetri *second)
{
	t_mino	*temp;
	t_mino	*temp2;
	int		i;

	i = 0;
	temp2 = second->fst;
	temp = parsed->content[i]->fst;
	while (parsed->content[i]->place != second->place)
	{
		while (temp)
		{
			while (temp2)
			{
				if (temp2->posx == temp->posx && temp2->posy == temp->posy)
					return (1);
				temp2 = temp2->next;
			}
			temp2 = second->fst;
			temp = temp->next;
		}
		i++;
		temp = parsed->content[i]->fst;
	}
	return (0);
}
