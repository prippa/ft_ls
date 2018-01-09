/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:49:17 by prippa            #+#    #+#             */
/*   Updated: 2017/12/20 17:49:20 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_dispatcher(t_printf *fpf, t_flag *flg)
{
	if (FC == 'c' || FC == 'C')
		fpf->size += ft_output_c_modul(flg);
	else if (FC == 's' || FC == 'S')
		fpf->size += ft_output_s_modul(flg);
	else if (FC == 'd' || FC == 'i' || FC == 'D')
		fpf->size += ft_output_d_modul(flg);
	else if (FC == 'u' || FC == 'U')
		fpf->size += ft_output_u_modul(flg);
	else if (FC == 'o' || FC == 'O' || FC == 'x' || FC == 'X')
		fpf->size += ft_output_ox_modul(flg);
	else if (FC == 'p')
		fpf->size += ft_output_p_modul(flg);
	else
		fpf->size += write(1, flg->str, ft_strlen(flg->str));
}

static t_flag	ft_initialization(t_printf *fpf)
{
	t_flag flg;

	ft_bzero(flg.flag, FLAG_SIZE);
	flg.width = 0;
	flg.precision = 0;
	flg.size_flag = 0;
	flg.type = '\0';
	flg.str = NULL;
	ft_get_flags(fpf, &flg);
	ft_get_type(fpf, &flg);
	return (flg);
}

static void		ft_lobi(t_printf *fpf)
{
	t_flag flg;

	while (PC)
	{
		if (PC == '%')
		{
			fpf->i++;
			if (!PC)
				continue;
			flg = ft_initialization(fpf);
			if (flg.type && flg.str)
			{
				ft_dispatcher(fpf, &flg);
				free(flg.str);
			}
			else
				fpf->i--;
		}
		else
			fpf->size += write(1, &PC, 1);
		fpf->i++;
	}
}

int				ft_printf(const char *format, ...)
{
	t_printf	fpf;

	fpf.format = ft_strdup(format);
	fpf.size = 0;
	fpf.i = 0;
	va_start(fpf.args, format);
	ft_lobi(&fpf);
	va_end(fpf.args);
	free(fpf.format);
	return (fpf.size);
}
