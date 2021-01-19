/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:15:22 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/19 18:26:14 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_dot_flag(t_flags flags, char *s)
{
	if (*(s + 1) == '-' || !ft_isdigit(*(s + 1)))
		flags.error = 1;
	if (ft_isdigit(*(s + 1)))
	{
		flags.dot = ft_atoi(s + 1);
		flags.zero = 0;
	}
	if (*(s + 1) == '*')
	{
		flags.dot = '*';
		flags.error = 0;
	}
	return (flags);
}

t_flags	ft_minus_flag(t_flags flags, char *s)
{
	if ((ft_isdigit(*(s + 1)) || *(s + 1) == '*') && flags.width == 0)
		flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_width_flag(t_flags flags, char *s)
{
	flags.width = ft_atoi(s);
	return (flags);
}

t_flags	ft_joker_flag(t_flags flags, va_list ap)
{
	flags.joker = (int) va_arg(ap, int);
	if (flags.dot == '*')
	{
		flags.dot = flags.joker;
		if (flags.dot < 0)
			flags.dot = -1;
		else
			flags.zero = 0;
	}
	else
	{
		if (flags.joker < 0)
		{
			flags.minus = 1;
			flags.width = flags.joker *= -1;
			flags.zero = 0;
		}
		else
			flags.width = flags.joker;
	}
	return (flags);
}

int	ft_update_index(char *s, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.width != 0 && s[i] != '.')
		i = ft_strlen(ft_itoa(flags.width)) - 1;
	if (flags.dot != -1)
		while (ft_isdigit(s[i + 1]))
			i++;
	return (i);
}
