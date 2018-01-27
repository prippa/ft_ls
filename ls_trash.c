/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:32:35 by prippa            #+#    #+#             */
/*   Updated: 2018/01/27 17:32:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_color(int c)
{
	c %= 7;
	if (c == 0)
		ft_putstr(LS_RED);
	else if (c == 1)
		ft_putstr(LS_YELLOW);
	else if (c == 2)
		ft_putstr(LS_GREEN);
	else if (c == 3)
		ft_putstr(LS_CYAN);
	else if (c == 4)
		ft_putstr(LS_BLUE);
	else if (c == 5)
		ft_putstr(LS_MAGENTA);
	else if (c == 6)
		ft_putstr(LS_NORMAL);
}
