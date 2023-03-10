/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strtoimg.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 21:36:50 by ehollidg       #+#    #+#                */
/*   Updated: 2019/07/08 21:36:50 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		strtoimg(t_img *img, t_tga *tga, unsigned char *str)
{
	size_t i;
	size_t j;
	size_t size;	
	size_t max;

	i = 19 + tga->idlen;
	if (tga->clr_map_type == 2)
		i += tga->cmlen * (tga->cmsize / 4);
	size = img->pxdepth / 8;
	img->pixels = (unsigned int*)ft_memalloc(sizeof(unsigned int) *
				(img->height * img->width));
	max = (img->height * img->width * size) + i;
	j = 0;
	while (i < max)
	{
		img->pixels[j] = pixelfrompos(str, i, img);
		i += size;
		j++;
	}
}
