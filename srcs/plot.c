/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plot.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 16:36:24 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/06 11:50:32 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	inbounds(int x, int y, t_mlx *mlx)
{
	if (x >= 0 && y >= 0 && x < mlx->image.width && y < mlx->image.height)
		return (1);
	return (0);
}

void		plot(int x, int y, unsigned int colour, t_mlx *mlx)
{
	int *i_img;

	i_img = mlx->img_add;
	//ft_putbytes(&colour, 4);
	//ft_putchar('\n');
	if (inbounds(x, y, mlx))
		ft_memcpy(&i_img[(y * mlx->image.width) + x], &colour, 4);
}
