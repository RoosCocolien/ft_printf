/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 14:57:08 by bvan-de-       #+#    #+#                */
/*   Updated: 2019/12/21 16:52:50 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_printtlist(t_list *list);
void				ft_printelem(t_list *elem);
int					ft_strcharfind(const char *s, int c);
char				*ft_strsldup(const char *src, int start, int lengte);
size_t				ft_strnlen(const char *str, char n);
void				ft_lstpushback(t_list **begin_list,\
					void *content, size_t content_size);
int					ft_sqrt(int nb);
int					ft_atoi(const char *str);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t lengte);
char				*ft_strncpy(char *dst, const char *src, size_t lengte);
char				*ft_strnstr(const char *haystack, const char *needle
					, size_t len);
char				*ft_strnstr(const char *haystack, const char *needle
					, size_t len);
char				*ft_strrchr(const char *s, int c);
void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strdup(const char *src);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_putnbr(int nb);
void				ft_putstr(const char *str);
void				ft_putchar(char	c);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s1, char c);
char				*ft_itoa(int n);
char				*ft_itoa_base(int value, int base);
char				*ft_itoa_base_cap(int value, int base);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *cont, size_t cont_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_digit_count(unsigned long long value, int base);
int					ft_intlength(unsigned long long y);
char				*ft_itoa_base_ll(intmax_t value, int base, int cap);
char				*ft_itoa_llu(unsigned long long n);

#endif
