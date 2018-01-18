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
	if (argc == 1)
		ls_show_dir(".");
	else
		ls_show_dir(argv[1]);
	return (0);
}


// int		main(void)
// {
// 	char **file_name;
// 	int i = 0;
// 	file_name = (char **)malloc(sizeof(char *) * 9 + 1);
// 	file_name[0] = (char *)malloc(sizeof(char) * FILE_NAME_SIZE);
// 	strcpy(file_name[0], "ft_ls");
// 	file_name[1] = (char *)malloc(sizeof(char) * FILE_NAME_SIZE);
// 	strcpy(file_name[1], "libft");
// 	file_name[2] = (char *)malloc(sizeof(char) * FILE_NAME_SIZE);
// 	strcpy(file_name[2], "Makefile");
// 	file_name[3] = (char *)malloc(sizeof(char) * FILE_NAME_SIZE);
// 	strcpy(file_name[3], "main.c");
// 	file_name[4] = (char *)malloc(sizeof(char) * FILE_NAME_SIZE);
// 	strcpy(file_name[4], "libft.a");
// 	file_name[5] = (char *)malloc(sizeof(char) * FILE_NAME_SIZE);
// 	strcpy(file_name[5], "t_ls.h");
// 	file_name[6] = (char *)malloc(sizeof(char) * FILE_NAME_SIZE);
// 	strcpy(file_name[6], "obj");
// 	file_name[7] = (char *)malloc(sizeof(char) * FILE_NAME_SIZE);
// 	strcpy(file_name[7], "author");
// 	file_name[8] = (char *)malloc(sizeof(char) * FILE_NAME_SIZE);
// 	strcpy(file_name[8], "ls_show.c");
// 	file_name[9] = NULL;
// 	while (file_name[i])
// 	{
// 		printf("%s\n", file_name[i]);
// 		i++;
// 	}
// 	return (0);
// }