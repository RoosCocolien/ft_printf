/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_normal.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: thugo <marvin@42.fr>                         +#+                     */
/*                                                   +#+                      */
/*   Created: 2017/01/25 22:17:08 by thugo          #+#    #+#                */
/*   Updated: 2019/10/16 14:43:15 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include "../includes/macros.h"

static void	tests_basic(void)
{
	ADD_PRINTF_TEST("")
	ADD_PRINTF_TEST("h")
	ADD_PRINTF_TEST("Hello\0Hello")
	ADD_PRINTF_TEST("h")
	ADD_PRINTF_TEST("\t")
}

static void tests_di(void)
{
	ADD_PRINTF_TEST("%hhd", 0)
	ADD_PRINTF_TEST("%hhd", CHAR_MAX)
	ADD_PRINTF_TEST("%hhd", CHAR_MIN)
	ADD_PRINTF_TEST("%hhd", CHAR_MAX + 42)
	ADD_PRINTF_TEST("%hhd", CHAR_MIN - 42)
	ADD_PRINTF_TEST("%d", 0)
	ADD_PRINTF_TEST("%d", INT_MAX)
	ADD_PRINTF_TEST("%d", INT_MIN)
	ADD_PRINTF_TEST("%d", INT_MIN - 1)
	ADD_PRINTF_TEST("%d", INT_MAX + 1)
	ADD_PRINTF_TEST("%hd", 0)
	ADD_PRINTF_TEST("%hd", SHRT_MAX)
	ADD_PRINTF_TEST("%hd", SHRT_MIN)
	ADD_PRINTF_TEST("%hd", SHRT_MAX + 5)
	ADD_PRINTF_TEST("%hd", SHRT_MIN - 5)
	ADD_PRINTF_TEST("%ld", 0)
	ADD_PRINTF_TEST("%ld", LONG_MAX)
	ADD_PRINTF_TEST("%ld", LONG_MIN)
	ADD_PRINTF_TEST("%ld", LONG_MAX + 18)
	ADD_PRINTF_TEST("%ld", LONG_MIN - 18)
	ADD_PRINTF_TEST("%lld", 0)
	ADD_PRINTF_TEST("%lld", LLONG_MAX)
	ADD_PRINTF_TEST("%lld", LLONG_MIN)
	ADD_PRINTF_TEST("%lld", LLONG_MAX + 3)
	ADD_PRINTF_TEST("%lld", LLONG_MIN - 3)
	// ADD_PRINTF_TEST("%jd", 0)
	// ADD_PRINTF_TEST("%jd", INTMAX_MAX)
	// ADD_PRINTF_TEST("%jd", INTMAX_MIN)
	// ADD_PRINTF_TEST("%jd", INTMAX_MAX + 3)
	// ADD_PRINTF_TEST("%jd", INTMAX_MIN - 3)
	// ADD_PRINTF_TEST("%zd", 0)
	// ADD_PRINTF_TEST("%zd", -42)
	// ADD_PRINTF_TEST("%zd", LONG_MAX)
	// ADD_PRINTF_TEST("%zd", LONG_MIN)
	// ADD_PRINTF_TEST("%zd", LONG_MAX + 3)
	// ADD_PRINTF_TEST("%zd", LONG_MIN - 3)
	// ADD_PRINTF_TEST("%D", 0)
	// ADD_PRINTF_TEST("%D", LONG_MAX)
	// ADD_PRINTF_TEST("%D", LONG_MIN)
	// ADD_PRINTF_TEST("%D", LONG_MAX + 42)
	// ADD_PRINTF_TEST("%D", LONG_MIN - 42)
	ADD_PRINTF_TEST("%+.0d", 0)
	ADD_PRINTF_TEST("%+.5d", 55)
	ADD_PRINTF_TEST("%+ 04d", 40)
	ADD_PRINTF_TEST("%+05d", 55)
	ADD_PRINTF_TEST("%.5d", -42)
	//ADD_PRINTF_TEST("%++ ++ d", 482642)  										#infinite loop
	ADD_PRINTF_TEST("%047.d", 482)
	ADD_PRINTF_TEST("%0.47d", -481)
	ADD_PRINTF_TEST("%+042d", 482)
	ADD_PRINTF_TEST("%+-042d", -482)
	ADD_PRINTF_TEST("%i", INT_MAX)
	ADD_PRINTF_TEST("%i", INT_MIN)
	ADD_PRINTF_TEST("%i", INT_MAX + 5)
	ADD_PRINTF_TEST("%i", INT_MIN - 5)
	ADD_PRINTF_TEST("%+042i", -15)
	ADD_PRINTF_TEST("%+42lli", LLONG_MAX)
	ADD_PRINTF_TEST("%-42hhi", LONG_MAX)
	ADD_PRINTF_TEST("%d %d %i%li %d", 45, 28, 96, LONG_MAX, 201506784)
}

static void	tests_o(void)
{
	ADD_PRINTF_TEST("%o", 0)
	ADD_PRINTF_TEST("%o", -42)
	ADD_PRINTF_TEST("%o", UINT_MAX)
	ADD_PRINTF_TEST("%o", UINT_MAX + 12)
	ADD_PRINTF_TEST("%hho", 0)
	ADD_PRINTF_TEST("%hho", -1)
	ADD_PRINTF_TEST("%hho", UCHAR_MAX)
	ADD_PRINTF_TEST("%hho", UCHAR_MAX + 5)
	ADD_PRINTF_TEST("%ho", 0)
	ADD_PRINTF_TEST("%ho", -4)
	ADD_PRINTF_TEST("%ho", USHRT_MAX)
	ADD_PRINTF_TEST("%ho", USHRT_MAX + 5)
	ADD_PRINTF_TEST("%lo", 0)
	ADD_PRINTF_TEST("%lo", -246)
	ADD_PRINTF_TEST("%lo", ULONG_MAX)
	ADD_PRINTF_TEST("%lo", ULONG_MAX + 5)	
	ADD_PRINTF_TEST("%llo", 0)
	ADD_PRINTF_TEST("%llo", -246)
	ADD_PRINTF_TEST("%llo", ULLONG_MAX)
	ADD_PRINTF_TEST("%llo", ULLONG_MAX + 5)
	ADD_PRINTF_TEST("%jo", 0)
	ADD_PRINTF_TEST("%jo", -246)
	ADD_PRINTF_TEST("%jo", UINTMAX_MAX)
	ADD_PRINTF_TEST("%jo", UINTMAX_MAX + 5)
	ADD_PRINTF_TEST("%zo", 0)
	ADD_PRINTF_TEST("%zo", -246)
	ADD_PRINTF_TEST("%zo", SIZE_MAX)
	ADD_PRINTF_TEST("%zo", SIZE_MAX + 5)
	ADD_PRINTF_TEST("%.3o", 1)
	ADD_PRINTF_TEST("%#0.3o", 0)
	ADD_PRINTF_TEST("%#.3o", 1)
	ADD_PRINTF_TEST("%#0.3o", 1)
	ADD_PRINTF_TEST("%#09.0o", 482)
	// ADD_PRINTF_TEST("%#04096o", 1337)  										#infinite loop
	//ADD_PRINTF_TEST("%.5o", 4826)  									
	//ADD_PRINTF_TEST("%#0#4lo", 0)  								
	ADD_PRINTF_TEST("%O", UINT_MAX)
	ADD_PRINTF_TEST("%O", -1)
	ADD_PRINTF_TEST("%O", 0)
	ADD_PRINTF_TEST("%O", INT_MIN - 5)
	ADD_PRINTF_TEST("%+042O", -15)
	ADD_PRINTF_TEST("%+42llO", LLONG_MAX)
	ADD_PRINTF_TEST("%-42hhO", LONG_MAX)
	ADD_PRINTF_TEST("%o %o %O%lo %O", 45, 28, 96, LONG_MAX, 201506784)
}

static void	tests_x(void)
{
	ADD_PRINTF_TEST("%x", 0)
	ADD_PRINTF_TEST("%x", -42)
	ADD_PRINTF_TEST("%x", UINT_MAX)
	ADD_PRINTF_TEST("%x", UINT_MAX + 12)
	ADD_PRINTF_TEST("%hhx", 0)
	ADD_PRINTF_TEST("%hhx", -1)
	ADD_PRINTF_TEST("%hhx", UCHAR_MAX)
	ADD_PRINTF_TEST("%hhx", UCHAR_MAX + 5)
	ADD_PRINTF_TEST("%hx", 0)
	ADD_PRINTF_TEST("%hx", -4)
	ADD_PRINTF_TEST("%hx", USHRT_MAX)
	ADD_PRINTF_TEST("%hx", USHRT_MAX + 5)
	ADD_PRINTF_TEST("%lx", 0)
	ADD_PRINTF_TEST("%lx", -246)
	ADD_PRINTF_TEST("%lx", ULONG_MAX)
	ADD_PRINTF_TEST("%lx", ULONG_MAX + 5)	
	ADD_PRINTF_TEST("%llx", 0)
	ADD_PRINTF_TEST("%llx", -246)
	ADD_PRINTF_TEST("%llx", ULLONG_MAX)
	ADD_PRINTF_TEST("%llx", ULLONG_MAX + 5)
	ADD_PRINTF_TEST("%jx", 0)
	ADD_PRINTF_TEST("%jx", -246)
	ADD_PRINTF_TEST("%jx", UINTMAX_MAX)
	ADD_PRINTF_TEST("%jx", UINTMAX_MAX + 5)
	ADD_PRINTF_TEST("%zx", 0)
	ADD_PRINTF_TEST("%zx", -246)
	ADD_PRINTF_TEST("%zx", SIZE_MAX)
	ADD_PRINTF_TEST("%zx", SIZE_MAX + 5)
	ADD_PRINTF_TEST("%x", 58)
	ADD_PRINTF_TEST("%#.5x", 0)
	ADD_PRINTF_TEST("%#.5x", 32)  										
	ADD_PRINTF_TEST("%#09.0X", 482)  									
	//ADD_PRINTF_TEST("%--.5x", 42)
	ADD_PRINTF_TEST("%-8X", 42)
	//ADD_PRINTF_TEST("%#04x", 0)
	//ADD_PRINTF_TEST("%##########x", 587)
}

static void	tests_u(void)
{
	ADD_PRINTF_TEST("%u", 0)
	ADD_PRINTF_TEST("%u", -42)
	ADD_PRINTF_TEST("%u", UINT_MAX)
	ADD_PRINTF_TEST("%u", UINT_MAX + 12)
	ADD_PRINTF_TEST("%hhu", 0)
	ADD_PRINTF_TEST("%hhu", -1)
	ADD_PRINTF_TEST("%hhu", UCHAR_MAX)
	ADD_PRINTF_TEST("%hhu", UCHAR_MAX + 5)
	ADD_PRINTF_TEST("%hu", 0)
	ADD_PRINTF_TEST("%hu", -4)
	ADD_PRINTF_TEST("%hu", USHRT_MAX)
	ADD_PRINTF_TEST("%hu", USHRT_MAX + 5)
	ADD_PRINTF_TEST("%lu", 0)
	ADD_PRINTF_TEST("%lu", -246)
	ADD_PRINTF_TEST("%lu", ULONG_MAX)
	ADD_PRINTF_TEST("%lu", ULONG_MAX + 5)	
	ADD_PRINTF_TEST("%llu", 0)
	ADD_PRINTF_TEST("%llu", -246)
	ADD_PRINTF_TEST("%llu", ULLONG_MAX)
	ADD_PRINTF_TEST("%llu", ULLONG_MAX + 5)
	ADD_PRINTF_TEST("%ju", 0)
	ADD_PRINTF_TEST("%ju", -246)
	ADD_PRINTF_TEST("%ju", UINTMAX_MAX)
	ADD_PRINTF_TEST("%ju", UINTMAX_MAX + 5)
	ADD_PRINTF_TEST("%zu", 0)
	ADD_PRINTF_TEST("%zu", -246)
	ADD_PRINTF_TEST("%zu", SIZE_MAX)
	ADD_PRINTF_TEST("%zu", SIZE_MAX + 5)
	ADD_PRINTF_TEST("%u", 58)
	ADD_PRINTF_TEST("%.5u", 0)
	ADD_PRINTF_TEST("%.5u", 32)
	ADD_PRINTF_TEST("%09.0U", 482)
	// ADD_PRINTF_TEST("%--.5U", 42)
	ADD_PRINTF_TEST("%-8U", 42)
	ADD_PRINTF_TEST("%04u", 0)
	ADD_PRINTF_TEST("%U", 587)
	ADD_PRINTF_TEST("%5u%u %.0U %.5u %05u", 4, 50, 0, LONG_MAX, 0)
}

void	tests_p(void)
{
	ADD_PRINTF_TEST("%p", 0)
	ADD_PRINTF_TEST("%p", -42)
	ADD_PRINTF_TEST("%p", LONG_MAX)
	ADD_PRINTF_TEST("%p", LONG_MAX + 12)
	ADD_PRINTF_TEST("%p", -1)
	ADD_PRINTF_TEST("%p", 58)
	ADD_PRINTF_TEST("%.5p", 0)
	ADD_PRINTF_TEST("%.5p", 32)
	ADD_PRINTF_TEST("%9.0p", 482)
	//ADD_PRINTF_TEST("%--.5p", 42)
	ADD_PRINTF_TEST("%-8p", 42)
	ADD_PRINTF_TEST("%4p", 0)
	ADD_PRINTF_TEST("%48p", 587)
	ADD_PRINTF_TEST("%p %5p %.2p %.15p %.15p", 5, 4896548, 15694, 0, -1)
}

void	tests_c(void)
{
	ADD_PRINTF_TEST("%c", 0)
	ADD_PRINTF_TEST("%c", 'a')
	ADD_PRINTF_TEST("%c", -1)
	ADD_PRINTF_TEST("%lc", 0x24)
	ADD_PRINTF_TEST("%lc", 0xa2)
	//ADD_PRINTF_TEST("%lc", 0x20ac)
	//ADD_PRINTF_TEST("%lc", 0x10348)
	// ADD_PRINTF_TEST("%C", 0x24)
	// ADD_PRINTF_TEST("%C", 0xa2)
	// ADD_PRINTF_TEST("%C", 0x20ac)
	// ADD_PRINTF_TEST("%C", 0x10348)
	ADD_PRINTF_TEST("%5c", 0)
	ADD_PRINTF_TEST("%5c", 'b')
	// ADD_PRINTF_TEST("%--5C", L'a')							infinite loop
	// ADD_PRINTF_TEST("%5C", L'®')
	// ADD_PRINTF_TEST("%c  %C  %5C %5c %5lc", 0, 0, 0x20ac, 'x', L'L')
}

void	tests_s(void)
{
	ADD_PRINTF_TEST("%s", "")
	ADD_PRINTF_TEST("%s", "Hello world %s!")
	ADD_PRINTF_TEST("%s This is a string %s", ">>", "<<")
	ADD_PRINTF_TEST("%.s", "hide")
	ADD_PRINTF_TEST("%.5s", "kqkunqagrwaihnowtnqekdhegbufx")
	ADD_PRINTF_TEST("%5s", "")
	ADD_PRINTF_TEST("%s", NULL)
	ADD_PRINTF_TEST("%.3s", NULL)
	ADD_PRINTF_TEST("%50.3s", NULL)
	ADD_PRINTF_TEST("%.4s", "123456789")
	ADD_PRINTF_TEST("%.42s", "123456789")
	ADD_PRINTF_TEST("%-50s", "-50")
	ADD_PRINTF_TEST("%.50s", "cc")
	//ADD_PRINTF_TEST("%S", L"®©∆∑˙ø∆µ≤∑π∂")
	// ADD_PRINTF_TEST("%S", L"")
	// ADD_PRINTF_TEST("%S", L"abcdefghi24800565631")
	//ADD_PRINTF_TEST("%S", L"å´goqogoq©œßˆ˙µßø")
	//ADD_PRINTF_TEST("%.S", L"hide®")
	//ADD_PRINTF_TEST("%.5S", L"†œø˙Unicode string")
	// ADD_PRINTF_TEST("%5S", L"Risitas¬")
	// ADD_PRINTF_TEST("%S", NULL)
	// ADD_PRINTF_TEST("%.3S", NULL)
	// ADD_PRINTF_TEST("%.50S", L"cc")
	// ADD_PRINTF_TEST("%-50S", L"®")
	// ADD_PRINTF_TEST("%-15S", L"")
	//ADD_PRINTF_TEST("%ls", L"∆´åø˚ßƒ")
	//ADD_PRINTF_TEST("%.0ls", L"fasg")
	//ADD_PRINTF_TEST("%5.2ls", L"IQ˙µåˆ˙π≈")
	//ADD_PRINTF_TEST("Hello %S %s this %5ls is big %-S", L"Tim®", " arg ", L"this\0is", L"Ω≈ç√∫˜µ")
}

static void	tests_mod(void)
{
	ADD_PRINTF_TEST("%%")
	ADD_PRINTF_TEST("% %")
	ADD_PRINTF_TEST("%10%")
	ADD_PRINTF_TEST("%-10%")
	ADD_PRINTF_TEST("%-%")
}

void	normal_tests(void)
{
	INIT_TESTS()
	printf("\033[34m=============== Normal tests ===============\033[0m\n");
	
	tests_basic();
	tests_di();
	tests_o();
	tests_x();
	tests_u();
	tests_p();
	tests_c();
	tests_s();
	tests_mod();

	PRINT_TESTS_RESULT("Normal tests")
}
