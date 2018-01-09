/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:41:47 by prippa            #+#    #+#             */
/*   Updated: 2018/01/04 11:41:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_flags(t_printf *fpf, t_flag *flg)
{
	while (PC)
	{
		if (PC == '-')
			flg->flag[F_MINUS] = '-';
		else if (PC == '+')
			flg->flag[F_PLUS] = '+';
		else if (PC == ' ')
			flg->flag[F_SPACE] = ' ';
		else if (PC == '#')
			flg->flag[F_SHARP] = '#';
		else if (PC == '0')
			flg->flag[F_ZERO] = '0';
		else if (PC == '*')
		{
			if ((flg->width = va_arg(fpf->args, int)) < 0)
			{
				flg->flag[F_MINUS] = '-';
				flg->width = flg->width * -1;
			}
		}
		else
			return ;
		fpf->i++;
	}
}

static void		ft_get_width_or_precision(t_printf *fpf, t_flag *flg, char c)
{
	char	wipi[20];
	int		i;

	i = 0;
	while (ft_isdigit(PC) && i < 20)
	{
		wipi[i] = PC;
		fpf->i++;
		i++;
	}
	wipi[i] = '\0';
	if (i)
	{
		if (c == 'w')
			flg->width = ft_atoi(wipi);
		else if (c == 'p')
			flg->precision = ft_atoi(wipi);
	}
	else if (c == 'p')
		flg->precision = 0;
}

static void		ft_precision(t_printf *fpf, t_flag *flg)
{
	while (PC)
	{
		if (PC == '.')
			flg->flag[F_DOT] = '.';
		else
			break ;
		fpf->i++;
	}
	if (flg->flag[F_DOT])
	{
		if (PC == '*')
		{
			while (PC == '*')
			{
				flg->precision = va_arg(fpf->args, int);
				fpf->i++;
			}
		}
		else
			ft_get_width_or_precision(fpf, flg, 'p');
	}
}

static void		ft_size_flag(t_printf *fpf, t_flag *flg)
{
	while (SIZE_FLAGS(PC))
	{
		if (PC == 'l' && PC_1 == 'l' && flg->size_flag < SF_LL
			&& (flg->size_flag = SF_LL))
			fpf->i += 2;
		else if (PC == 'l' && flg->size_flag < SF_L
			&& (flg->size_flag = SF_L))
			fpf->i += 1;
		else if (PC == 'h' && PC_1 == 'h' && flg->size_flag < SF_HH
			&& (flg->size_flag = SF_HH))
			fpf->i += 2;
		else if (PC == 'h' && flg->size_flag < SF_H
			&& (flg->size_flag = SF_H))
			fpf->i += 1;
		else if (PC == 'j' && flg->size_flag < SF_J
			&& (flg->size_flag = SF_J))
			fpf->i += 1;
		else if (PC == 'z' && flg->size_flag < SF_Z
			&& (flg->size_flag = SF_Z))
			fpf->i += 1;
		else
			fpf->i++;
	}
}

void			ft_get_flags(t_printf *fpf, t_flag *flg)
{
	while (SIZE_FLAGS(PC) || FLAGS(PC) || BONUS_FLAGS(PC) || ft_isdigit(PC))
	{
		ft_flags(fpf, flg);
		ft_get_width_or_precision(fpf, flg, 'w');
		ft_precision(fpf, flg);
		ft_size_flag(fpf, flg);
	}
}
