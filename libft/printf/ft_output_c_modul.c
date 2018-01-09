/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_c_modul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 12:04:55 by prippa            #+#    #+#             */
/*   Updated: 2018/01/05 12:04:58 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_modul_wchar(t_flag *flg)
{
	int	len;
	int	size;
	int	print;

	len = ft_strlen(flg->str);
	print = 1;
	size = 0;
	if (flg->flag[F_MINUS] && !(print = 0))
		size += write(1, flg->str, len);
	if (flg->width)
	{
		if (flg->flag[F_ZERO] && !flg->flag[F_MINUS])
			size += ft_print_width(flg->width - len, '0');
		else
			size += ft_print_width(flg->width - len, ' ');
	}
	if (print)
	{
		if (flg->str[0])
			size += write(1, flg->str, len);
		else
			size += write(1, &flg->str[0], 1);
	}
	return (size);
}

static int	ft_modul_char(t_flag *flg)
{
	int	size;
	int	print;

	print = 1;
	size = 0;
	if (flg->flag[F_MINUS] && !(print = 0))
		size += write(1, &flg->str[0], 1);
	if (flg->width)
	{
		if (flg->flag[F_ZERO] && !flg->flag[F_MINUS])
			size += ft_print_width(flg->width - 1, '0');
		else
			size += ft_print_width(flg->width - 1, ' ');
	}
	if (print)
		size += write(1, &flg->str[0], 1);
	return (size);
}

int			ft_output_c_modul(t_flag *flg)
{
	int	size;

	if (flg->size_flag || FC == 'C')
		size = ft_modul_wchar(flg);
	else
		size = ft_modul_char(flg);
	return (size);
}
