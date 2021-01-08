/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:18:29 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/08 11:36:42 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_convert(char c, va_list ap, t_flags flags, t_flags empty_flags)
{
	char	*arg;
	
	if (c == 's')
	{
		arg = (char *) va_arg(ap, char *);
		if (arg == NULL)
			arg = "(null)";	
		if (ft_is_flags_empty(flags, empty_flags))
			return (ft_putn_and_count(arg, ft_strlen(arg)));
		else
			return(ft_print_str(arg, flags, c));
	}
	if (c == 'c')
	{
		if (ft_is_flags_empty(flags, empty_flags))
			return (ft_print_char(ap, flags) + 1);
		return (ft_print_char(ap, flags));
	}
	return (0);
}

int	ft_int_convert(char c, va_list ap, t_flags flags, t_flags empty_flags)
{
	char		*arg;
	int	count;

	count = (int) va_arg(ap, int);
	if (c == 'd' || c == 'i')
	{
		if (flags.dot == 0 && count == 0)
		{
			write(1, "", 1);
			return (0);
		}
		arg = ft_itoa(count);
	}
	if (ft_is_flags_empty(flags, empty_flags))
		return (count = ft_putn_and_count(arg, ft_strlen(arg)));
	else
		return (ft_print_int(arg, flags, c));
	free(arg);
	return (count);
}

int	ft_convert(char c, t_flags flags, va_list ap)
{
	char	*arg;
	int		count;
	t_flags empty_flags;

	count = 0;
	empty_flags = ft_init_flags();
	if (ft_is_char_convertor(c))
		count = ft_char_convert(c, ap, flags, empty_flags);
	if (ft_is_int_convertor(c))
		count = ft_int_convert(c, ap, flags, empty_flags);
//	if (ft_is_hexa_convertor(c))
//		arg = ft_hexa_convert(c, ap);
//	if (ft_is_other_convertor(c))
//		arg = ft_other_convert(c, ap);
	else
		arg = 0;
	return (count);
}



/*	printf("\n\n--------START ANALYSIS-----------\n\n");
	printf("arg[0] = %c\n",arg[0]);
	printf("arg[1] = %c\n",arg[1]);
	printf("arg[2] = %c\n",arg[2]);
	printf("arg[3] = %c\n",arg[3]);
	printf("arg[4] = %c\n",arg[4]);
	printf("arg[5] = %c\n",arg[5]);
	printf("arg[6] = %c\n",arg[6]);
	printf("arg[7] = %c\n",arg[7]);
	printf("arg[8] = %c\n",arg[8]);
	printf("arg[9] = %c\n",arg[9]);
	printf("arg[10] = %c\n",arg[10]);
	printf("arg[11] = %c\n",arg[11]);
	printf("\n\n------------END ANALYSIS----------\n\n");
*/