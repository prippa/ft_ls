/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:25:00 by prippa            #+#    #+#             */
/*   Updated: 2018/01/02 13:25:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int	ft_conv_unsig_int(t_printf *fpf, int size_flag)
{
	unsigned long long int num;

	if (size_flag == SF_HH)
		num = (unsigned char)va_arg(fpf->args, unsigned long long int);
	else if (size_flag == SF_H)
		num = (unsigned short)va_arg(fpf->args, unsigned long long int);
	else if (size_flag == SF_L)
		num = (unsigned long)va_arg(fpf->args, unsigned long long int);
	else if (size_flag == SF_LL)
		num = (unsigned long long)va_arg(fpf->args, unsigned long long int);
	else if (size_flag == SF_J)
		num = (uintmax_t)va_arg(fpf->args, unsigned long long int);
	else if (size_flag == SF_Z)
		num = (size_t)va_arg(fpf->args, unsigned long long int);
	else
		num = (unsigned int)va_arg(fpf->args, unsigned long long int);
	return (num);
}
