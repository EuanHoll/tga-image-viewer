/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controls.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 19:01:03 by ehollidg       #+#    #+#                */
/*   Updated: 2019/07/09 19:01:03 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	closep(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void		controls(t_mlx *mlx)
{
	mlx_hook(mlx->win, CLOSE_EVENT, 0, closep, mlx);
}
