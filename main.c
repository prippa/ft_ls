/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:54:06 by prippa            #+#    #+#             */
/*   Updated: 2018/01/08 17:54:08 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_lspath pth;

	if (argc == 1)
	{
		ls_print_dir(".");
		return (0);
	}
	else
	{
		ls_get_args(&pth, argv + 1);
		ft_printf("%c|%c|%c|%c|%c\n", pth.flags[R_BIG], pth.flags[R_MINI],
			pth.flags[A_MINI], pth.flags[L_MINI], pth.flags[T_MINI]);
		// if (!(ls_print_dir(argv[1])))
		// {
		// 	if (!(ls_print_file(argv[1])))
		// 		ft_printf("ls: %s: No such file or directory\n", argv[1]);
		// }
	}
	//system("leaks ft_ls");
	return (0);
}