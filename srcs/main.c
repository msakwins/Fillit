/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:47:18 by bbeldame          #+#    #+#             */
/*   Updated: 2016/12/27 20:11:42 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	reader(int fd, char *buf)
{
	int		ret;

	ret = read(fd, buf, BUF_SIZE);
	if (ret == -1)
		return (0);
	close(fd);
	buf[ret] = '\0';
	return (1);
}

static int	error(int fd)
{
	ft_putendl("error");
	close(fd);
	return (-1);
}

static int	check_all_errors(char *str)
{
	if (ft_check_char(str, 0, 0, 0))
		return (0);
	if (ft_check_size(str))
		return (0);
	if (ft_check_form(str))
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	int			fd;
	char		str[BUF_SIZE + 1];
	t_square	*parsed;

	if (ac != 2)
	{
		ft_putendl("usage: fillit input_file");
		return (-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (error(fd));
	if (!reader(fd, str))
		return (error(fd));
	if (!check_all_errors(str))
		return (error(fd));
	parsed = parse(str, 0);
	backtrack(parsed);
	display(parsed);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
