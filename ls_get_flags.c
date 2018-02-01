/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:01:10 by prippa            #+#    #+#             */
/*   Updated: 2018/01/23 15:01:18 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ls_filter1(t_lspath *pth, int c)
{
	if (c == 'R')
		pth->flags[R_BIG] = 'R';
	else if (c == 'r')
		pth->flags[R_MINI] = 'r';
	else if (c == 'a')
		pth->flags[A_MINI] = 'a';
	else if (c == 'l')
		pth->flags[L_MINI] = 'l';
	else if (c == 't')
		pth->flags[T_MINI] = 't';
	else if (c == 'G')
		pth->flags[G_BIG] = 'G';
	else if (c == 'v')
		pth->flags[V_MINI] = 'v';
	else if (c == 'y')
		pth->flags[Y_MINI] = 'y';
	else if (c == 'S')
		pth->flags[S_BIG] = 'S';
	else if (c == 'A')
		pth->flags[A_BIG] = 'A';
	else if (c == '1')
		pth->flags[L_MINI] = '\0';
	else
		return (c);
	return (0);
}

int			ls_get_flags(t_lspath *pth, char **argv)
{
	PI = 0;
	while (argv[PI] && argv[PI][0] == '-')
	{
		PJ = 1;
		if (!argv[PI][PJ])
			return (0);
		if (argv[PI][PJ] == '-' && !argv[PI][PJ + 1])
			return (0);
		while (argv[PI][PJ])
		{
			if (ls_filter1(pth, argv[PI][PJ]) > 0)
				return ((int)argv[PI][PJ]);
			PJ++;
		}
		PI++;
	}
	return (0);
}
