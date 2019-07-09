/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixelfrompos.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 18:55:48 by ehollidg       #+#    #+#                */
/*   Updated: 2019/07/09 18:55:48 by ehollidg      ########   odam.nl         */
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

static int	b16(unsigned char *str, size_t i)
{
	unsigned char	g;
	unsigned int	ret;
	
	//prop wrong
	g  = (str[i] & 0xe0) >> 5;
	g  |= (str[i + 1] & 0x7) << 3;
	ret = g << 16;
	ret |= (str[i] & 0x1f) << 8;
	ret |= str[i + 1] & 0xf8;
	ft_putstr("16 BIT!\n");
	return (ret);
}

static int	b15(unsigned char *str, size_t i)
{
	unsigned int	ret;

	//prop wrong
	ret = str[i + 1] << 16;
	ret |= str[i + 0] << 8;
	ret |= str[i + 2];
	ft_putstr("16 BIT!\n");
	return (ret);
}

static int	b8(unsigned char *str, size_t i)
{
	unsigned int	ret;
	
	ret = (unsigned char)(((float)((str[i] & 0x7)) / 8) * 256) << 16; //21
	ret |= (unsigned char)(((float)((str[i] & 0x38) >> 3) / 8) * 256) << 8;  //10
	ret |= (unsigned char)(((float)((str[i] & 0xC0) >> 6) / 4) * 256);
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
	if (img->pxdepth == 16)
		return (b16(str, i));
	if (img->pxdepth == 15)
		return (b15(str, i));
	if (img->pxdepth == 8)
		return (b8(str, i));
	return (0);
}
