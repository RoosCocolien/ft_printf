/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_deci_count.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/24 18:07:39 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/24 18:21:18 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int     ft_deci_count(double d)
{
    int i;

    i = 0;
    while (d > 10)
    {
        d = d / 10;
        i++;
    }
    return (i);
}
