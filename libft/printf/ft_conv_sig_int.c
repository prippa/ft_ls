/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_signed_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:24:38 by prippa            #+#    #+#             */
/*   Updated: 2018/01/02 13:24:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ft_conv_sig_int(t_printf *fpf, int size_flag)
{
	long long int num;

	if (size_flag == SF_HH)
		num = (signed char)va_arg(fpf->args, long long int);
	else if (size_flag == SF_H)
		num = (short)va_arg(fpf->args, long long int);
	else if (size_flag == SF_L)
		num = (long)va_arg(fpf->args, long long int);
	else if (size_flag == SF_LL)
		num = (long long)va_arg(fpf->args, long long int);
	else if (size_flag == SF_J)
		num = (intmax_t)va_arg(fpf->args, long long int);
	else if (size_flag == SF_Z)
		num = (size_t)va_arg(fpf->args, long long int);
	else
		num = (int)va_arg(fpf->args, long long int);
	return (num);
}
