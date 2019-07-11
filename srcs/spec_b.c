/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:33 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/04 12:54:19 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void    ft_print_int_arr(int *arr, int len)
{
    int i;

    i = 0;
    while (i <= 3)
    {
        ft_putnbr(arr[i]);
        i++;
    }
}

static void     bin_filler(int **bin_2d_arr, int bin)
{
    int i;
    int j;
    int remain;
    int len;
    int *arr_0;
    int *arr_1;

    i = 1;
    len = 0;
    while (i < bin)
    {
        i = i * 2;
        len++;
    }
    i = i / 2;
    len--;
    ft_putnbr(len);
    arr_0 = (int*)malloc(len); //len wijzigen
    arr_1 = (int*)malloc(len);
    arr_0[0] = i;
    arr_1[0] = 1;
    j = 1;
    while (j < len)
    {
        bin = bin - i;
        while (i > bin)
        {
            arr_1[j] = 0;
            i = i / 2;
            j++;
        }
        arr_1[j] = 1;
        j++;
    }
    ft_print_int_arr(arr_1, len);
}

int		spec_b(char *s, va_list args, t_info *flag, int x)
{
    int bin;
    int bin_len;
    int remain;
    int **bin_2d_arr;
    
    bin = va_arg(args, int);
    bin_2d_arr = (int**)malloc(2);
    bin_filler(bin_2d_arr, bin);
    
	return (x + 1);
}