/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:52:26 by prippa            #+#    #+#             */
/*   Updated: 2017/12/20 17:52:28 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>

# define SF_H			1
# define SF_HH			2
# define SF_L			3
# define SF_LL			4
# define SF_J			5
# define SF_Z			6

# define F_MINUS		0
# define F_PLUS			1
# define F_SPACE		2
# define F_SHARP		3
# define F_ZERO			4
# define F_DOT			5

# define FLAG_SIZE		6

# define PC fpf->format[fpf->i]
# define PC_1 fpf->format[fpf->i + 1]
# define FC flg->type
# define SIZE_FLAGS(c) (c == 'l' || c == 'h' || c == 'j' || c == 'z')
# define FLAGS(c) (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
# define BONUS_FLAGS(c) (c == '*' || c == '.')
# define MAX(a, b) (a > b ? a : b)

typedef	struct			s_flag
{
	char				flag[FLAG_SIZE];
	int					width;
	int					precision;
	int					size_flag;
	char				type;
	char				*str;
}						t_flag;

typedef	struct			s_printf
{
	char				*format;
	int					i;
	int					size;
	va_list				args;
}						t_printf;

int						ft_printf(const char *format, ...);
void					ft_get_flags(t_printf *fpf, t_flag *flg);
void					ft_get_type(t_printf *fpf, t_flag *flg);
char					*ft_wstr_to_str(wchar_t *ws);
long long int			ft_conv_sig_int(t_printf *fpf, int size_flag);
unsigned long long int	ft_conv_unsig_int(t_printf *fpf, int size_flag);

char					*ft_get_c(t_printf *fpf, char c, int size_flag);
char					*ft_get_s(t_printf *fpf, char c, int size_flag);
char					*ft_get_oux(t_printf *fpf, char c, int size_flag);
char					*ft_get_di(t_printf *fpf, char c, int size_flag);
char					*ft_get_p(t_printf *fpf);

int						ft_print_width(int n, char c);
int						ft_output_c_modul(t_flag *flg);
int						ft_output_s_modul(t_flag *flg);
int						ft_output_d_modul(t_flag *flg);
int						ft_output_u_modul(t_flag *flg);
int						ft_output_ox_modul(t_flag *flg);
int						ft_output_p_modul(t_flag *flg);

#endif
