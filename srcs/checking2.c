/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:26:29 by msakwins          #+#    #+#             */
/*   Updated: 2016/12/27 19:42:29 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_zelda(char **tab, int i, int j, int x)
{
	int		link;
	int		fst;

	fst = (x == 0) ? 0 : 1;
	link = 0;
	if (tab[(i + x) - fst][j] == '#' && x != 0)
		link++;
	if (tab[(i + x)][j + 1] == '#')
		link++;
	if (tab[(i + x)][j - 1] == '#')
		link++;
	if (x != 3)
		if (tab[(i + x) + 1][j] == '#')
			link++;
	return (link);
}

int		ft_check_link(char **tab)
{
	int i;
	int j;
	int x;
	int link;

	i = 0;
	while (tab[i])
	{
		link = 0;
		x = 0;
		while (x != 4)
		{
			j = 0;
			while (tab[i + x][j])
				if (tab[i + x][j++] == '#')
					link += ft_check_zelda(tab, i, j - 1, x);
			x++;
		}
		i += x;
		if (link != 6 && link != 8)
			return (1);
	}
	return (0);
}

int		ft_check_piece(char **tab)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
				count++;
			j++;
		}
		i++;
		j = 0;
	}
	return (i - count);
}

int		ft_check_form(char *str)
{
	char	**tab;

	tab = ft_strsplit(str, '\n');
	return (ft_check_link(tab) + ft_check_piece(tab));
}
