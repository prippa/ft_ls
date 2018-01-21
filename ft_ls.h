/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:14:36 by prippa            #+#    #+#             */
/*   Updated: 2018/01/21 17:14:41 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf.h"
# include "libft.h"

# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <uuid/uuid.h>
# include <dirent.h>
# include <limits.h>
# include <errno.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>

# define FILE_NAME_SIZE 255
# define I ls->i
# define J ls->j
# define FNI ls->file_name[I]
# define FNJ ls->file_name[I][J]

# define LS_FLAG_SIZE 5

typedef struct			s_ls
{
	char				**file_name;
	int					i;
	int					j;
}						t_ls;

typedef struct			s_lsflag
{
	char				flags[LS_FLAG_SIZE];
	char				*path;
	int					i;
	int					j;
}						t_lsflag;

void					ls_print(char *path);
void					ls_base_sort(t_ls *ls);
void					ls_readdir(t_ls *ls, DIR *directory, char *path);
void					ls_free(t_ls *ls);

#endif
