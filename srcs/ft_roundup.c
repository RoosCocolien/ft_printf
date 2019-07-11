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

long long unsigned     ft_roundup(long long unsigned d)
{
    long long int i;
    int len;
    int j;
    char *str;
    
    i = d * 1000000;
    len = ft_intlength(i);
    str = ft_itoa_llu(i);
    j = len;
    //printf("d oud = %llu\n", d);
    if (str[len - 6] >= '5')
    {
        //printf("d niewuw = %llu\n", d);
        str[len - 7] += 1;
        d += 1;
    }
    return (d);
}
