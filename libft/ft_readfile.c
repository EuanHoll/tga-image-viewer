/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_readfile.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 16:10:42 by ehollidg       #+#    #+#                */
/*   Updated: 2019/07/21 16:16:50 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_readfile(int id)
{
    char    *str;
    char    temp[BUFF_SIZE + 1];
    int     add;

    str = NULL;
    if (read(id, &str, 0) < 0)
        return (str);
    add = read(id, &str, BUFF_SIZE);
    while (add > 0)
    {
        add = read(id, &temp, BUFF_SIZE);
        ft_strappend(str, temp);
        ft_strclr(temp);
    }
    return (str);
}
