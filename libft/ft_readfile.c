/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_readfile.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 18:30:38 by pholster       #+#    #+#                */
/*   Updated: 2019/04/04 12:02:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*join(char *str1, char *str2, size_t str1len, size_t str2len)
{
	char			*str;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	str = ft_strnew(str1len + str2len);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, str1, str1len);
	ft_memcpy(&str[str1len], str2, str2len);
	return (str);
}

char	*ft_readfile(int fd)
{
	size_t	len;
	char	*str;
	char	buff[BUFF_SIZE + 1];
	int		ret;

	len = 0;
	str = NULL;
	ft_bzero(buff, BUFF_SIZE + 1);
	ret = (int)read(fd, buff, BUFF_SIZE);
	while (ret >= 0)
	{
		if (str == NULL)
			str = ft_memdup(buff, ret);
		else
			ft_strreplace(&str, join(str, buff, len, ret));
		len += ret; 
		if (str == NULL)
			return (NULL);
		if (ret == 0)
			break ;
		ft_bzero(buff, BUFF_SIZE + 1);
		ret = (int)read(fd, buff, BUFF_SIZE);
	}
	return (str);
}
