/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oOuU.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:44:35 by prippa            #+#    #+#             */
/*   Updated: 2018/01/02 13:44:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_oux(t_printf *fpf, char c, int size_flag)
{
	char	*str;

	if (c == 'o')
		str = ft_itoa_base(ft_conv_unsig_int(fpf, size_flag), 8, 0);
	else if (c == 'O')
		str = ft_itoa_base(ft_conv_unsig_int(fpf, SF_L), 8, 0);
	else if (c == 'u')
		str = ft_itoa_base(ft_conv_unsig_int(fpf, size_flag), 10, 0);
	else if (c == 'U')
		str = ft_itoa_base(ft_conv_unsig_int(fpf, SF_L), 10, 0);
	else if (c == 'x')
		str = ft_itoa_base(ft_conv_unsig_int(fpf, size_flag), 16, 87);
	else
		str = ft_itoa_base(ft_conv_unsig_int(fpf, size_flag), 16, 55);
	if (!str)
		return (NULL);
	return (str);
}
