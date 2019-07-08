/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 15:49:25 by ehollidg       #+#    #+#                */
/*   Updated: 2019/07/01 15:49:25 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> //Remove

typedef struct	s_img
{
	int				width;
	int				height;
	unsigned int	*pixels;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img_pt;
	void	*img_add;
	t_img	image;
}				t_mlx;

int			opentga(t_img *img, char *loc);
void		plot(int x, int y, int colour, t_mlx *mlx);

#endif
