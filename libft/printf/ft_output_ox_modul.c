/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_ox_modul.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 12:01:00 by prippa            #+#    #+#             */
/*   Updated: 2018/01/07 12:01:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_percision_tricks(t_flag *flg, int *len)
{
	if (flg->flag[F_DOT] && !flg->precision && flg->str[0] == '0'
		&& !flg->flag[F_SHARP])
		*len = 0;
	if (flg->flag[F_DOT] && !flg->precision && flg->str[0] == '0'
		&& flg->flag[F_SHARP] && (FC == 'x' || FC == 'X'))
		*len = 0;
	if (flg->flag[F_DOT] && flg->precision
		&& flg->flag[F_SHARP] && (FC == 'o' || FC == 'O'))
		flg->flag[F_SHARP] = '\0';
}

static int		ft_write_sharp(t_flag *flg)
{
	int size;

	size = 0;
	if (FC == 'x')
		size += write(1, "0x", 2);
	else if (FC == 'X')
		size += write(1, "0X", 2);
	else if (FC == 'o' || FC == 'O')
		size += write(1, "0", 1);
	return (size);
}

static int		ft_base_ox_modul_logic(t_flag *flg, int len)
{
	int size;

	size = 0;
	if (flg->width && flg->flag[F_SHARP] && FC != 'o' && FC != 'O')
		flg->width -= 2;
	else if (flg->width && flg->flag[F_SHARP] && (FC == 'o' || FC == 'O'))
		flg->width--;
	if (flg->width)
	{
		if (flg->flag[F_ZERO] && !flg->precision)
		{
			if (flg->flag[F_SHARP])
				size += ft_write_sharp(flg);
			size += ft_print_width(flg->width - len, '0');
		}
		else
			size += ft_print_width(flg->width - MAX(len, flg->precision), ' ');
	}
	if (flg->flag[F_SHARP] && flg->str[0] != '0'
		&& (!flg->flag[F_ZERO] || !flg->width))
		size += ft_write_sharp(flg);
	if (flg->precision)
		size += ft_print_width(flg->precision - len, '0');
	size += write(1, flg->str, len);
	return (size);
}

int				ft_output_ox_modul(t_flag *flg)
{
	int	len;
	int	size;

	len = ft_strlen(flg->str);
	ft_percision_tricks(flg, &len);
	size = 0;
	if (flg->flag[F_MINUS])
	{
		if (flg->flag[F_SHARP] && len)
			size += ft_write_sharp(flg);
		if (flg->precision)
			size += ft_print_width(flg->precision - len, '0');
		size += write(1, flg->str, len);
		if (flg->width)
			size += ft_print_width(flg->width - size, ' ');
	}
	else
		size += ft_base_ox_modul_logic(flg, len);
	return (size);
}
