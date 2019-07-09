/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 15:44:50 by ehollidg       #+#    #+#                */
/*   Updated: 2019/07/01 15:44:50 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			setup(t_mlx *mlx, char *loc)
{
	int tmp;

	tmp = 0;
	if (!opentga(&mlx->image, loc))
		return (0);
	mlx->mlx = mlx_init();
	printf("Screen Size %i %i\n", mlx->image.width, mlx->image.height);
	mlx->win = mlx_new_window(mlx->mlx, mlx->image.width, mlx->image.height, "TGA Viewer");
	mlx->img_pt = mlx_new_image(mlx->mlx, mlx->image.width, mlx->image.height);
	mlx->img_add = mlx_get_data_addr(mlx->img_pt, &tmp, &tmp, &tmp);
	displayimage(mlx);
	return (1);
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		if (!setup(&mlx, argv[1]))
		{
			ft_putendl("Please Enter a valid file");
			return (0);
		}
		controls(&mlx);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
