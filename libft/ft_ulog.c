/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaber <neyl.jaber@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 22:34:05 by njaber            #+#    #+#             */
/*   Updated: 2017/12/25 22:38:15 by njaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ulog(uintmax_t n, uintmax_t b)
{
	size_t	i;

	i = 1;
	if (b == 1 || b == 0)
		return (0);
	while ((n /= b) != 0)
		i++;
	return (i);
}