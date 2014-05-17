/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:39:25 by gmange            #+#    #+#             */
/*   Updated: 2014/03/02 13:39:16 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "struct_libft.h"

# define MIN_INT		-2147483648
# define MIN_LLONG		-922337203854775808
# define MAX_LEN_NBR	20
# define SIX_MTH_SEC	15768000

/*
** maybe SIX_MTH_SEC should be 15552000
*/

/*
** fonctions from lib C
*/

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
** additional fonctions from 42
*/

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
** fonctions for t_lists from 42
*/

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdellast(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** fonctions for t_lists - personnal
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstaddtoend(t_list **lst, t_list *new);
t_list	*ft_lstaddnew(t_list **lst, void const *content, size_t content_size);
t_list	*ft_lstnewtoend(t_list **lst, void const *content, size_t content_size);
void	ft_lstdelif(t_list **alst, size_t size, void (*del)(void *, size_t));

/*
** fonctions for display
*/

void	ft_putmemchar(void *ptr, size_t n);
void	ft_putmemchar_fd(void *ptr, size_t n, int fd);
void	ft_putmemcharl(void *ptr, size_t n);
void	ft_putmemcharl_fd(void *ptr, size_t n, int fd);
void	ft_putnchar(char c, size_t n);
void	ft_putnchar_fd(char c, size_t n, int fd);
void	ft_putncharl(char c, size_t n);
void	ft_putncharl_fd(char c, size_t n, int fd);
void	ft_putnbrl(int n);
void	ft_putnbrl_fd(int n, int fd);

/*
** personnal functions
*/

void	ft_swap(int *x, int *y);
int		ft_memlen(const void *s, int c, size_t n);
size_t	ft_strichr(const char *s, int c);
size_t	ft_strirchr(const char *s, int c);
size_t	ft_stristr(const char *s1, const char *s2);
size_t	ft_nbrlen(int n);
char	**ft_strdupchar2(const char **s1);
void	ft_freechar2(char ***c2);
void	ft_putchar2(char **str);
char	*ft_strcpy2(char *s1, const char *s2, const char *s3);
char	*ft_strdup3(const char *s1, const char *s2, const char *s3);
char	ft_endianness(void);
int		ft_is_wht_spc(const char c);
size_t	ft_ptrlen(const void *p);
char	*ft_strrpl(char *s, char *src, char *dst);
char	*ft_strtoupper(char *str);
char	*ft_strtolower(char *str);
float	ft_atof(const char *str);

#endif
