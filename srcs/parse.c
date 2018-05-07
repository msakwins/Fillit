/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:09:24 by bbeldame          #+#    #+#             */
/*   Updated: 2016/12/27 19:42:58 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			getsize(t_square *sq)
{
	int		i;
	t_mino	*tmp;
	int		max;

	i = 0;
	max = 2;
	while (sq->content[i])
	{
		tmp = sq->content[i]->fst;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->posx > 2 || tmp->posy > 2)
			max = 4;
		if (tmp->posx > 1 || tmp->posy > 1)
			if (max != 4)
				max = 3;
		i++;
	}
	return (max);
}

t_mino				*mini(t_mino *fst)
{
	t_mino	*tmp;
	int		minx;
	int		miny;

	minx = fst->posx;
	miny = fst->posy;
	tmp = fst;
	while (tmp)
	{
		minx = (tmp->posx < minx) ? tmp->posx : minx;
		miny = (tmp->posy < miny) ? tmp->posy : miny;
		tmp = tmp->next;
	}
	tmp = fst;
	while (tmp)
	{
		tmp->posx = tmp->posx - minx;
		tmp->posy = tmp->posy - miny;
		tmp = tmp->next;
	}
	return (fst);
}

static t_mino		*pml(t_mino *fst, char **tab, int i)
{
	int		j;
	int		len;
	t_mino	*tmp;

	i = i * 4;
	len = i + 4;
	if (!(tmp = (t_mino *)malloc(sizeof(t_mino))))
		return (NULL);
	fst = tmp;
	while (i++ < len)
	{
		j = 0;
		while (j++ < 4)
			if (tab[i - 1][j - 1] == '#')
			{
				if (!(tmp->next = (t_mino *)malloc(sizeof(t_mino))))
					return (NULL);
				tmp->posy = i - 1;
				tmp->posx = j - 1;
				tmp = tmp->next;
			}
	}
	free(fst->next->next->next->next);
	fst->next->next->next->next = NULL;
	return (fst);
}

t_square			*parse(const char *str, int i)
{
	char		**tab;
	t_square	*sq;

	if (!(sq = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	tab = ft_strsplit(str, '\n');
	while (tab[i])
		i++;
	sq->size = i;
	if (!(sq->content = (t_tetri **)malloc(sizeof(t_tetri *) * (i / 4 + 1))))
		return (NULL);
	i = 0;
	while (i++ < sq->size / 4)
	{
		if (!(sq->content[i - 1] = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		sq->content[i - 1]->place = i - 1;
		sq->content[i - 1]->fst = pml(sq->content[i - 1]->fst, tab, i - 1);
		sq->content[i - 1]->fst = mini(sq->content[i - 1]->fst);
	}
	sq->content[i - 1] = NULL;
	sq->size = getsize(sq);
	return (sq);
}
