/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:36:13 by jeseo             #+#    #+#             */
/*   Updated: 2022/08/08 15:00:46 by jeseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recusive_print(long long n, int *count)
{
	char	c;
	int		temp;

	if (n < 10)
	{
		temp = *count;
		c = n + '0';
		*count += write(1, &c, 1);
		if (temp > *count)
			*count = -9999;
	}
	else
	{
		recusive_print(n / 10, count);
		recusive_print(n % 10, count);
	}
}

void	ft_itoa(long long n, int *count, int flag)
{
	long long	casting_n;
	int			temp;

	temp = *count;
	if (flag == 'u')
		casting_n = (unsigned int)n;
	else
		casting_n = n;
	if (casting_n < 0)
	{
		*count += write(1, "-", 1);
		casting_n *= -1;
	}
	if (*count < temp)
		return ;
	return (recusive_print(casting_n, count));
}
