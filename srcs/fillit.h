/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:42:33 by bbeldame          #+#    #+#             */
/*   Updated: 2016/12/27 20:11:46 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>

# define BUF_SIZE 1337

typedef struct		s_mino
{
	int				posy;
	int				posx;
	struct s_mino	*next;
}					t_mino;

typedef struct		s_tetri
{
	int				place;
	t_mino			*fst;
}					t_tetri;

typedef struct		s_square
{
	int				size;
	struct s_tetri	**content;
}					t_square;

int					ft_check_char(char *str, int i, int j, int k);
int					ft_check_size(char *str);
int					ft_check_form(char *str);
t_square			*parse(const char *str, int i);
int					solve_fillit(t_square *parsed, int i, int flag);
void				display(t_square *lilsq);
t_mino				*mini(t_mino *fst);
void				reset_sq(t_square *sq);
int					backtrack(t_square *sq);
int					next_permutation(t_square *sq, int i, int len, int j);
void				reset_full(t_square *sq);
void				reset_sq(t_square *sq);
int					count_mino(t_square *sq);
int					biggerthansize(t_mino *fst, int size);
int					canmove(t_mino *fst, int size);
int					touchi(t_square *parsed, t_tetri *second);
int					touchiall(t_square *parsed);

#endif
