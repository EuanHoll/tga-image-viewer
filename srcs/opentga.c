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

static void	settgaheader(char *str, t_tga *tga, t_img *img)
{
	tga->idlen = (str[0]);
	tga->clr_map_type = (str[1]);
	tga->img_type = (str[2]);
	tga->cmpos = (str[3] << 8) | str[4];
	tga->cmlen = (str[5] << 8) | str[6];
	tga->cmsize = str[7];
	img->xorigin = (str[10] << 8) | str[11];
	img->yorigin = (str[12] << 8) | str[13];
	img->width = (str[14] << 8) | str[15];
	img->height = (str[16] << 8) | str[17];
	tga->pxdepth = str[18];
}

int			opentga(t_img *img, char *loc)
{
	int		fd;
	char	*str;
	t_tga	tga;

	img--;
	fd = open(loc, O_RDONLY);
	if (fd == -1)
		return (0);
	str = ft_readfile(fd);
	close(fd);
	if (str == NULL)
		return (0);
	settgaheader(str, &tga, img);
	return (1);
}
