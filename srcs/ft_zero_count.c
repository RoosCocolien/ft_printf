/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_zero_count.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/24 18:07:39 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/24 18:09:37 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int     ft_zero_count(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '0')
            return (1);
        i++;
    }
    return (0);
}