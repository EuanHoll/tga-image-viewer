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

static int	pixelfrompos(unsigned char *str, size_t i, size_t size)
{
	unsigned int	ret;
	
	ret = ~str[i + 2] << 24;
	ret |= str[i + 1] << 16;
	ret |= str[i + 0] << 8;
	ret |= str[i + 3];
	(void)size;
	// ft_putendl("\nPair:");
	// ft_putbytes(&str[i], 4);
	// ft_putchar('\n');
	// ft_putbytes(&ret, 4);
	// ft_putchar('\n');
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
	size = img->pxdepth / 8;
	img->pixels = (unsigned int*)ft_memalloc(sizeof(unsigned int) *
				(img->height * img->width));
	max = (img->height * img->width * size) + i;
	j = 0;
	while (i < max)
	{
		img->pixels[j] = pixelfrompos((unsigned char *)str, i, size);
		i += size;
		j++;
	}
}
