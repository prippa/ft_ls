/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 13:43:08 by prippa            #+#    #+#             */
/*   Updated: 2018/01/04 13:43:10 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_get_type_1(t_printf *fpf, t_flag *flg)
{
	if (PC == 'o' && (FC = PC))
		flg->str = ft_get_oux(fpf, PC, flg->size_flag);
	else if (PC == 'O' && (FC = PC))
		flg->str = ft_get_oux(fpf, PC, flg->size_flag);
	else if (PC == 'u' && (FC = PC))
		flg->str = ft_get_oux(fpf, PC, flg->size_flag);
	else if (PC == 'U' && (FC = PC))
		flg->str = ft_get_oux(fpf, PC, flg->size_flag);
	else if (PC == 'x' && (FC = PC))
		flg->str = ft_get_oux(fpf, PC, flg->size_flag);
	else if (PC == 'X' && (FC = PC))
		flg->str = ft_get_oux(fpf, PC, flg->size_flag);
	else if (PC)
	{
		FC = 'c';
		if (!(flg->str = (char*)malloc(sizeof(char) * 2)))
			return ;
		flg->str[0] = PC;
		flg->str[1] = '\0';
	}
}

void		ft_get_type(t_printf *fpf, t_flag *flg)
{
	if (PC == 's' && (FC = PC))
		flg->str = ft_get_s(fpf, PC, flg->size_flag);
	else if (PC == 'd' && (FC = PC))
		flg->str = ft_get_di(fpf, PC, flg->size_flag);
	else if (PC == 'c' && (FC = PC))
		flg->str = ft_get_c(fpf, PC, flg->size_flag);
	else if (PC == 'S' && (FC = PC))
		flg->str = ft_get_s(fpf, PC, flg->size_flag);
	else if (PC == 'C' && (FC = PC))
		flg->str = ft_get_c(fpf, PC, flg->size_flag);
	else if (PC == 'D' && (FC = PC))
		flg->str = ft_get_di(fpf, PC, flg->size_flag);
	else if (PC == 'i' && (FC = PC))
		flg->str = ft_get_di(fpf, PC, flg->size_flag);
	else if (PC == 'p' && (FC = PC))
		flg->str = ft_get_p(fpf);
	else
		ft_get_type_1(fpf, flg);
}
