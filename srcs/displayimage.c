/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   displayimage.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 16:05:40 by ehollidg       #+#    #+#                */
/*   Updated: 2019/07/08 16:05:40 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		transferimage(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	while (x < mlx->image.width)
	{
		y = 0;
		while (y < mlx->image.height)
		{
			plot(x, y, mlx->image.pixels[(y * mlx->image.width) + x], mlx);
			y++;
		}
		x++;
	}
}

void		displayimage(t_mlx *mlx)
{
	transferimage(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_pt, 0, 0);
}
