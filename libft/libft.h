/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:29:31 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/14 20:25:04 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# define BUFF_SIZE 1024
# define HEX "abcdef"
# define HEX2 "ABCDEF"
# define TYPE "cspdiouxXf"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef struct		s_form
{
	char			*flags;
	int				wide;
	int				acu;
	int				size;
	int				type;
	int				d;
	int				m;
	int				cut;
}					t_form;

int					get_next_line(const int fd, char **line);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c,
					size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
size_t				ft_strlen(const char *c);
char				*ft_strdup(const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *dest, const char *app);
size_t				ft_strlcat(char *dest, const char *src,
					size_t size);
char				*ft_strncat(char *dest, const char *app, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strnstr(const char *str1, const char *str2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strsub_free(char *s, unsigned int start, size_t len);
char				*ft_strjoin_free(char *s1, char *s2, int free1, int free2);
int					ft_atoi_base(const char *str, int str_base);
char				*ft_itoa_base_h(unsigned long long int n, int base);
char				*ft_itoa_base(unsigned long long int n, int base);
char				*changetostr(long long int n);
long long int		ft_atoi_long(const char *str);
int					addaccu(char *str, int i, t_form *pt, va_list ap);
int					addsizetype(char *str, int i, t_form *pt);
int					writediftype(t_form *lst, va_list ap);
int					addsize(char *str, int i, t_form *pt);
int					addflags(char *str, int i, t_form *pt);
int					ft_printf(char *str, ...);
int					ifpercent(char *str, t_form *smt, va_list ap);
int					printstr (t_form *form, char *str);
int					printchar(t_form *form, int c);
int					printwide(t_form *form, int str);
int					printint(t_form *form, char **str);
char				*changetostr(long long int n);
int					ucountnum(unsigned long long int n);
char				*changeutostr(unsigned long long int n);
int					accuranceforint(t_form *form, int len);
int					wideforint(t_form *form, int len);
int					printminusint(t_form *form, char **str);
int					printminusint2(t_form *form, char **str, int i);
int					printsign(t_form *form, char **str);
int					floatsize(t_form *form, long double n);
int					printfloat(t_form *form, char *str);
char				*changefloat(t_form *form, long double n);
int					sizeforunsign(t_form *form, unsigned long long int n);
int					printunsignedint(t_form *form, char *str);
int					octalint(t_form *form, unsigned long long int n);
int					sizeforunsign(t_form *form, unsigned long long int n);
int					whatsize(t_form *form, long long int n);
int					hexalint(t_form *form, unsigned long long int n);
int					sizepointer(t_form *form, unsigned long long int n);
int					minushexoct(t_form *form, char **str);
int					hexoct(t_form *form, char **str);
int					acuforhexoct(t_form *form, int n);
void				fillerforstruct(t_form *smt);
int					addtype(char *str, int i, t_form *pt);
int					addwide(char *str, int i, t_form *pt, va_list ap);
int					minushexoct2(t_form *form, char **str);
int					hexoct4(t_form *form, char **str, int i, int n);
int					hexoct3(t_form *form, char **str);
int					hexoct2(t_form *form, char **str);
int					printint2(t_form *fo, char **str, int i);
int					printint3(t_form *fo, char **str, int i, int n);
char				*findzapyat(t_form *form, long double num, int *sym);
char				*rounding(char *str, int sym);
char				*rounding2(char *str, int i);
char				*findzapyat(t_form *form, long double num, int *sym);
#endif
