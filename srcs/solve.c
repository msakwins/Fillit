/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:44:52 by bbeldame          #+#    #+#             */
/*   Updated: 2016/12/27 20:09:04 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	rewindx(t_mino *first, int size, char c)
{
	t_mino *tmp;

	tmp = first;
	if (c == 'x')
		while (tmp)
		{
			tmp->posx = tmp->posx + size;
			tmp = tmp->next;
		}
	if (c == 'y')
	{
		tmp = first;
		while (tmp)
		{
			tmp->posy = tmp->posy + size;
			tmp = tmp->next;
		}
	}
}

void	goleft(t_mino *fst)
{
	t_mino		*tmp;
	int			minx;

	minx = fst->posx;
	tmp = fst;
	while (tmp)
	{
		minx = (tmp->posx < minx) ? tmp->posx : minx;
		tmp = tmp->next;
	}
	tmp = fst;
	while (tmp)
	{
		tmp->posx = tmp->posx - minx;
		tmp = tmp->next;
	}
}

int		move(t_square *parsed, int i)
{
	if (!canmove(parsed->content[i]->fst, parsed->size))
		return (0);
	if (!biggerthansize(parsed->content[i]->fst, parsed->size))
		rewindx(parsed->content[i]->fst, 1, 'x');
	else
	{
		goleft(parsed->content[i]->fst);
		rewindx(parsed->content[i]->fst, 1, 'y');
	}
	return (1);
}

void	normstfu(t_square *parsed, int i, t_mino *temp)
{
	while (touchi(parsed, parsed->content[i])
			&& !biggerthansize(temp, parsed->size))
		rewindx(temp, 1, 'x');
	if (touchi(parsed, parsed->content[i])
			|| !biggerthansize(temp, parsed->size))
	{
		if (canmove(temp, parsed->size) && touchi(parsed, parsed->content[i]))
		{
			goleft(temp);
			rewindx(temp, 1, 'y');
		}
	}
}

int		solve_fillit(t_square *parsed, int i, int flag)
{
	t_mino	*temp;

	if (!touchiall(parsed))
		return (1);
	if (i == 0 || i >= count_mino(parsed))
		return (0);
	temp = parsed->content[i]->fst;
	while (flag)
	{
		normstfu(parsed, i, temp);
		if (!touchi(parsed, parsed->content[i]))
			flag = 0;
		else if (!canmove(temp, parsed->size))
		{
			if (move(parsed, i - 1))
			{
				parsed->content[i]->fst = mini(parsed->content[i]->fst);
				solve_fillit(parsed, i - 1, 1);
			}
			else
				return (0);
		}
	}
	return (solve_fillit(parsed, i + 1, 1));
}
