/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:10:19 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/07 12:06:03 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags()
{
	t_flags flags;
	
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.joker = 0;
	return (flags);
}

int		ft_is_flags_empty(t_flags f1, t_flags f2)
{
	if (f1.width != f2.width || f1.minus != f2.minus ||\
	 f1.zero != f2.zero || f1.dot != f2.dot || f1.joker != f2.joker)
	 	return (0);
	return (1);
}
