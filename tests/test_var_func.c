/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_tester.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 12:32:53 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/05/25 12:36:24 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "../libft/includes/libft.h"

void    ft_putdouble(double d)
{
    int new_d_int;
    char *new_d_str;
    int i;
    // int j;
    int len;
    int count;

    new_d_int = d * 1000000;
    new_d_str = ft_itoa(new_d_int);
    len = ft_strlen(new_d_str);
    i = 0;
    while (new_d_str[i] != '\0')
    {
        if (i + 6 == len)
        {
            ft_putchar('.');
        }
        // if (new_d_str[i] == '0')
        // {
        //     j = i;
        //     while (new_d_str[j] != '\0')
        //     {
        //         if (new_d_str[j] != '0')
        //         {
        //             break ;
        //         }
        //         j++;
        //     }
        //     if (new_d_str[j] == '\0')
        //     {
        //         //printf("\n i + 6 = %d, len + 1 == %d", i + 6, len + 1);
        //         if (i + 6 == len + 1)
        //         {
        //             ft_putstr("00");
        //             //ft_putstr("break2");
        //         }
        //         if (i + 5 == len + 1)
        //         {
        //             ft_putstr("0");
        //         }
        //         break ;
        //     }
        // }
        ft_putchar(new_d_str[i]);
        i++;
    }
}

void    my_printf(char *str, int num, ...)
{
    va_list args;
    int i;
    int count;

    va_start(args, num);
    i = 0;
    count = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            if (str[i + 1] == 'd' || str[i + 1] == 'i')
                ft_putnbr(va_arg(args, int));
            if (str[i + 1] == 'c')
                ft_putchar(va_arg(args, int));
            if (str[i + 1] == 's')
                ft_putstr(va_arg(args, char*));
            if (str[i + 1] == 'f')
                ft_putdouble(va_arg(args, double));
            if (count < num)
                ft_putstr(", ");
            if (count >= num)
                ft_putchar('\n');
            count++;
        }
        i++;
    }
    va_end(args);
}

int main ()
{
    // my_printf("%c, %c, %d, %s, %f\n", 4, 'b', 'r', 77, "Bram is echt een zieke baas", 99.12312312321321);
    // printf("%c, %c, %d, %s, %f\n", 'b', 'r', 77, "Bram is echt een zieke baas", 99.12312312321321);
    printf("%+5d\n",0);
    printf("%+05d\n",0);
    printf("%+05d\n",0);
    printf("% 05d\n",0);
    printf("%2f", 2.718281828);
    return (1);
}