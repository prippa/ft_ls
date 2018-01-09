/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_p_modul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 12:01:12 by prippa            #+#    #+#             */
/*   Updated: 2018/01/07 12:01:15 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_base_p_modul_logic(t_flag *flg, int len)
{
	int	size;
	int	flag;

	size = 0;
	flg->width -= 2;
	flag = 1;
	if (flg->width)
	{
		if (flg->flag[F_ZERO] && !flg->precision)
		{
			flag = 0;
			size += write(1, "0x", 2);
			size += ft_print_width(flg->width - len, '0');
		}
		else
			size += ft_print_width(flg->width - MAX(len, flg->precision), ' ');
	}
	if (flag)
		size += write(1, "0x", 2);
	if (flg->precision)
		size += ft_print_width(flg->precision - len, '0');
	size += write(1, flg->str, len);
	return (size);
}

int			ft_output_p_modul(t_flag *flg)
{
	int	len;
	int	size;

	len = ft_strlen(flg->str);
	size = 0;
	if (flg->flag[F_DOT] && !flg->precision && flg->str[0] == '0')
		len = 0;
	if (flg->flag[F_MINUS])
	{
		size += write(1, "0x", 2);
		if (flg->precision)
			size += ft_print_width(flg->precision - len, '0');
		size += write(1, flg->str, len);
		if (flg->width)
			size += ft_print_width(flg->width - size, ' ');
	}
	else
		size += ft_base_p_modul_logic(flg, len);
	return (size);
}
