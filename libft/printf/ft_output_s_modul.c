/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s_modul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:01:19 by prippa            #+#    #+#             */
/*   Updated: 2018/01/05 14:01:20 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_rules(t_flag *flg, int len, int size, int print)
{
	if (!ft_strlen(flg->str))
	{
		len = 0;
		print = 0;
	}
	if (print && flg->flag[F_MINUS] && !(print = 0))
		size += write(1, flg->str, len);
	if (flg->width)
	{
		if (flg->flag[F_ZERO] && !flg->flag[F_MINUS])
			size += ft_print_width(flg->width - len, '0');
		else
			size += ft_print_width(flg->width - len, ' ');
	}
	if (print)
		size += write(1, flg->str, len);
	return (size);
}

int			ft_output_s_modul(t_flag *flg)
{
	int	len;
	int	size;
	int	print;

	len = ft_strlen(flg->str);
	if (flg->precision < 0)
		flg->precision = 0;
	else if (flg->precision)
	{
		if (FC == 'S' && !ft_isascii(flg->str[flg->precision - 1]))
		{
			while (flg->precision % 3 > 0)
				flg->precision--;
		}
		if (len > (int)flg->precision)
			len = flg->precision;
	}
	else if (flg->flag[F_DOT])
		len = flg->precision;
	size = 0;
	print = 1;
	size += ft_rules(flg, len, size, print);
	return (size);
}
