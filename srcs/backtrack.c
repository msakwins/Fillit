/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 22:42:46 by bbeldame          #+#    #+#             */
/*   Updated: 2016/12/27 20:07:36 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		next_permutation(t_square *sq, int i, int len, int j)
{
	t_tetri *temp;

	len = 0;
	while (sq->content[len])
		len++;
	len--;
	i = len;
	while (i > 0 && sq->content[i - 1]->place >= sq->content[i]->place)
		i--;
	if (i == 0)
		return (0);
	j = len;
	while (sq->content[j]->place <= sq->content[i - 1]->place)
		j--;
	temp = sq->content[i - 1];
	sq->content[i - 1] = sq->content[j];
	sq->content[j] = temp;
	j = len;
	while (i++ < j--)
	{
		temp = sq->content[i - 1];
		sq->content[i - 1] = sq->content[j + 1];
		sq->content[j + 1] = temp;
	}
	return (1);
}

void	reset_full(t_square *sq)
{
	t_tetri		*tmp;
	int			i;
	int			j;
	int			len;

	len = 0;
	while (sq->content[len])
		len++;
	j = 0;
	while (j <= len)
	{
		i = 0;
		while (sq->content[i + 1])
		{
			if (sq->content[i]->place > sq->content[i + 1]->place)
			{
				tmp = sq->content[i];
				sq->content[i] = sq->content[i + 1];
				sq->content[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

void	reset_sq(t_square *sq)
{
	int		i;

	i = 0;
	while (sq->content[i])
	{
		sq->content[i]->fst = mini(sq->content[i]->fst);
		i++;
	}
}

int		backtrack(t_square *sq)
{
	while (!solve_fillit(sq, 1, 1))
	{
		reset_sq(sq);
		if (!next_permutation(sq, 0, 0, 0))
		{
			sq->size++;
			reset_full(sq);
		}
	}
	return (1);
}
