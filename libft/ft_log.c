/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:14:51 by njaber            #+#    #+#             */
/*   Updated: 2017/11/30 02:05:40 by njaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_log(long n, long b)
{
	size_t	i;

	i = 1;
	if (b == 1 || b == 0)
		return (0);
	while ((n /= b) != 0)
		i++;
	return (i);
}