/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:58:33 by prippa            #+#    #+#             */
/*   Updated: 2018/01/02 15:58:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_c(t_printf *fpf, char c, int size_flag)
{
	char	*str;
	wchar_t	tmp[2];

	if (size_flag == SF_L || c == 'C')
		c = 'C';
	if (c == 'c')
	{
		if (!(str = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = (char)va_arg(fpf->args, int);
		str[1] = '\0';
	}
	else
	{
		tmp[0] = (wchar_t)va_arg(fpf->args, int);
		tmp[1] = '\0';
		if (!(str = ft_wstr_to_str(tmp)))
			return (NULL);
	}
	return (str);
}
