/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_roundup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/20 12:14:26 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/20 15:05:28 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

long long int     ft_roundup(long double d)
{
    long long int i;
    int len;
    int j;
    char *str;
    
    i = d * 1000000;
    len = ft_intlength(i);
    str = ft_itoa_llu(i);
    j = len;
    if (str[len - 6] >= '5')
    {
        str[len - 7] += 1;
        if (d < 0)
            d -= 1;
        else
            d += 1;
    }
    return (d);
}
