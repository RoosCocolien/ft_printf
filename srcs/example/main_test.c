/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_test.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 12:56:12 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/06 12:56:27 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

int		main(void)
{
	//simple test
	printf("printf\t\t%% int: %d char: %c float: %f float: %f string: %s\n", \
	3, 'a', 1.999, 42.5, "Roos");
	sim_print("sim_print\t%% int: %d char: %c float: %f float: %f %s is een dikzak\n", \
	3, 'a', 1.999, 42.5, "Roos");

	//backslash
	printf("printf\t\tQuotations in the \"middle\" of the sentence\n");
	sim_print("sim_print\tQuotations in the \"middle\" of the sentence\n");

	//percentage sign
	printf("printf\t\tThis is a percentage sign: %%\n");
	sim_print("sim_print\tThis is a percentage sign: %%\n");

	//decimals
	printf("This is a %%f %f\n", 25.4);
	sim_print("This is a %%f %f\n", 25.4);

	//negative numbers
	printf("Neg number: %i\n", -36);
	sim_print("Neg number: %i\n", -36);

	//FLAGS
	printf("**-----------------------**\n\tFLAGS 4 integers\n**-----------------------**\n");
	printf("******** right aligned, without fill option ********\n");
	printf("%5d\n", 45);

	printf("******** left aligned, without fill option ********\n");
	printf("%-5d\n", 45);

	printf("******** right aligned, with fill option 0 ********\n");
	printf("%05d\n", 45);
	//printf("%*5d\n", 45); you can't use '*' as fill option

	printf("******** left aligned, with fill option 0 ********\n");
	printf("error: flag 0 is ignored when '-' is present");
	/*printf("%-05d\n", 45);	flag 0 is ignored when '-' is present*/

	printf("******** request plus sign for pos & neg number ********\n");
	//requesting a plus sign
	printf("%+5d\n", 45);
	//requesting plus sign for neg number
	printf("%+5d\n", -45);

	//invisible plus sign && left aligned
	printf("******** left aligned && + sign ********\n");
	printf("%+-5d\n", 36);
	printf("+ - reversed\n");
	printf("%-+5d\n", 46);

	printf("******** left aligned && invisible + sign ********\n");
	printf("% -5d\n", 36);
	printf("% -5d\n", -36);

	printf("******** %%- 5d ********THIS IS STRANGE BEHAVIOR, the amount of spaces does not matter\n");
	//the minus sign prints a space before a positive number
	printf("%-   5d\n", 28);


	printf("**-----------------------**\n\tFLAGS 4 strings\n**-----------------------**\n");
	printf("zero fill (0), plus sign(+) and invisible plus( +) sign are meaningless\
	and will result in undefined behavior with 's' conversion specifier\n");
	printf("%5s\n", "");
	printf("%5s\n", "ab");
	printf("%5s\n", "abcdefghijklm");
	printf("%-5s\n", "");
	printf("%-5s\n", "ab");
	printf("%5s\n", "abcdefghijklm");

	printf("**-----------------------**\n\tFLAGS 4 floating point numbers\n**-----------------------**\n");
	printf("all the same flags and rules apply for floats as for ints\n");
	printf("precision examples\n");
	float nb = 2.7182818;
	printf("%.0f\n", nb);	//hij rondt alles af naar boven
	printf("%.0f.\n", nb);	//die punt na 'f' is gewoon onderdeel van de string
	printf("%.1f\n", nb);
	printf("%.2f\n", nb);
	printf("%.6f\n", nb);
	printf("%f\n", nb);
	printf("%.7f\n", nb);
	float nb2 = 0.7182818;
	printf("%.0f\n", nb2);
	printf("%.0f.\n", nb2);
	printf("%.1f\n", nb2);
	printf("%.5f\n", nb2);
	printf("%.9f\n", nb2);
	printf("%.11f\n", nb2);
	printf("default (6 decimal behind .): (%%f)\n");
	printf("%f\n", nb2);
	printf("\n******** standard flags 4 floating point numbers ********\n");
	printf("%5.1f\n", 2.73);
	printf("%-5.1f\n", 2.73);
	printf("%05.1f\n", 2.73);
	printf("%+5.1f\n", 2.73);
	printf("% 5.1f\n", 2.73);
	printf("%+-5.1f\nAND\n%-+5.1f\n", 2.73, 2.73);
	printf("spatie min:\n% -5.1f\nmin spatie\n%- 5.1f\n", 2.73, 2.73);
	printf("spatie min:\n% -5.1f\nmin spatie\n%- 5.1f\n", -2.73, -2.73);
	printf("% 05.1f\n", 2.73);
	printf("%+05.1f\n", 2.73);
	printf("\n% 5.1f\n", -33.44);

	return (0);
}
