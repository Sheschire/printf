/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 11:46:37 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/06 16:45:22 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "./libft/libft.h"

int main()
{
	char 	name[] = "T";
	char	age = '2';
	char	qi[] = "130";

	printf("Je suis %-.2s et j'ai %c ans et %.1s de QI.", name, age, qi);
}