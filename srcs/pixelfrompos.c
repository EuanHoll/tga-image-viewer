/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixelfrompos.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 18:55:48 by ehollidg       #+#    #+#                */
/*   Updated: 2019/07/21 18:32:58 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	b32(unsigned char *str, size_t i)
{
	unsigned int	ret;
	
	ret = ~str[i + 2] << 24;
	ret |= str[i + 1] << 16;
	ret |= str[i] << 8;
	ret |= str[i + 3];
	// ft_putendl("\nPair:");
	// ft_putbytes(&str[i], 4);
	// ft_putchar('\n');
	// ft_putbytes(&ret, 4);
	// ft_putchar('\n');
	return (ret);
}

static int	b24(unsigned char *str, size_t i)
{
	unsigned int	ret;
	
	ret = str[i + 1] << 16;
	ret |= str[i] << 8;
	ret |= str[i + 2];
	return (ret);
}

static int	b8(unsigned char *str, size_t i)
{
	unsigned int	ret;
	float			a;

	a = (float)(str[i] & 0x7) / (float)8;
	ret = ((unsigned char)(a * 255)) << 16; //21
	a = (float)((str[i] & 0x38) >> 3) / (float)8;
	ret |= (unsigned char)(a * 255) << 8;  //10
	a = (float)((str[i] & 0xC0) >> 6) / (float)4;
	ret |= (unsigned char)(a * 255);
	// ft_putendl("\nPair:");
	// ft_putbytes(&str[i], 1);
	// ft_putchar('\n');
	// ft_putbytes(&ret, 4);
	// ft_putchar('\n');
	(void)i;
	(void)str;
	return (ret);
}

int	pixelfrompos(unsigned char *str, size_t i, t_img *img)
{
	if (img->pxdepth == 32)
		return (b32(str, i));
	if (img->pxdepth == 24)
		return (b24(str, i));
	if (img->pxdepth == 16 || img->pxdepth == 15)
	{
		ft_putendl("Error 16/15 bit image");
		return (0);
	}
	if (img->pxdepth == 8)
		return (b8(str, i));
	return (0);
}
