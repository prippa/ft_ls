/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sS.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:48:07 by prippa            #+#    #+#             */
/*   Updated: 2018/01/02 15:48:12 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_s(t_printf *fpf, char c, int size_flag)
{
	void	*data;
	char	*str;

	data = va_arg(fpf->args, void *);
	if (!data)
	{
		if (!(str = ft_strdup("(null)")))
			return (NULL);
		return (str);
	}
	if (size_flag == SF_L)
		c = 'S';
	if (c == 's')
	{
		if (!(str = ft_strdup((char *)data)))
			return (NULL);
	}
	else
	{
		if (!(str = ft_wstr_to_str((wchar_t *)data)))
			return (NULL);
	}
	return (str);
}
