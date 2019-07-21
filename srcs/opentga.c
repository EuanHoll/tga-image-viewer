/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opentga.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 16:13:59 by ehollidg       #+#    #+#                */
/*   Updated: 2019/07/21 18:28:05 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void printheader(t_img *img, t_tga *tga)
{
	printf("ID Length -> %i\n", tga->idlen);
	printf("Colour Image Map Type -> %i\n", tga->clr_map_type);
	printf("Image Type -> %i\n", tga->img_type);
	printf("Colour Map Length -> %i\n", tga->cmlen);
	printf("Image Width -> %i\n", img->width);
	printf("Image Height -> %i\n", img->height);
	printf("Pixel Depth -> %i\n", img->pxdepth);
}

static void	settgaheader(unsigned char *str, t_tga *tga, t_img *img)
{
	tga->idlen = (str[0]);
	tga->clr_map_type = (str[1]);
	tga->img_type = (str[2]);
	tga->cmpos = (str[4] << 8) | str[3];
	tga->cmlen = (str[6] << 8) | str[5];
	tga->cmsize = str[7];
	img->xorigin = (str[9] << 8) | str[8];
	img->yorigin = (str[11] << 8) | str[10];
	img->width = (str[13] << 8) | str[12];
	img->height = (str[15] << 8) | str[14];
	img->pxdepth = str[16];
	//printheader(img, tga);
}

int			opentga(t_img *img, char *loc)
{
	int		fd;
	unsigned char	*str;
	t_tga	tga;

	fd = open(loc, O_RDONLY);
	if (fd == -1)
		return (0);
	str = (unsigned char *)ft_readfile(fd);
	close(fd);
	if (str == NULL)
		return (0);
	settgaheader(str, &tga, img);
	if (tga.img_type == 0)
		return (0);
	strtoimg(img, &tga, str);
	return (1);
}
