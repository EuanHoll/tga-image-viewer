/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opentga.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 16:13:59 by ehollidg       #+#    #+#                */
/*   Updated: 2019/07/01 16:13:59 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			opentga(t_img *img, char *loc)
{
	int		x;
	int		y;

loc--;
	img->height = 50;
	img->width = 50;
	x = 0;
	img->pixels = (unsigned int*)ft_memalloc(sizeof(unsigned int) * (size_t)(img->width * img->height));
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			img->pixels[(y * img->width) + x] = 0xFFFFFF;
			y++;
		}
		x++;
	}
	return (1);
}
