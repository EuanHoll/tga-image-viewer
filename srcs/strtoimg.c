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

static int	pixelfrompos(char *str, size_t i, size_t size)
{
	unsigned int	ret;
	int				j;

	j = size - 1;
	ret = 0;
	while (j >= 0)
	{
		ret = (ret << 4) | str[i + (size_t)j];
		j--;
	}
	return (ret);
}

void		strtoimg(t_img *img, t_tga *tga, char *str)
{
	size_t i;
	size_t j;
	size_t size;	
	size_t max;

	i = 19 + tga->idlen;
	if (tga->clr_map_type != 0)
		i += tga->cmlen * (tga->cmsize / 4);
	size = img->pxdepth / 4;
	img->pixels = (unsigned int*)ft_memalloc(sizeof(unsigned int) *
				(img->height * img->width));
	max = (img->height * img->width * size) + i;
	ft_printf("Size %zu, Max %zu, i %i\n", size, max, tga->cmlen);
	j = 0;
	while (i < max)
	{
		img->pixels[j] = pixelfrompos(str, i, size);
		i += size;
		ft_putbytes(&img->pixels[j], size);
		ft_putchar('\n');
		j++;
	}
	ft_putendl("Finished Setting");
}
