/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 07:57:33 by meid              #+#    #+#             */
/*   Updated: 2025/03/20 12:01:17 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int						ft_atoi(const char *str);
void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t count, size_t size);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memset(void *b, int c, size_t len);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strdup(const char *s1);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
int						ft_strlen(const char *str);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
int						ft_tolower(int c);
int						ft_toupper(int c);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s1, char const *set);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
char					*ft_itoa(int n);
char					*ft_strmapi(char const *s,
							char (*f)(unsigned int, char));
char					**ft_split(char const *s, char c);
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
int						ft_is(int c, char *str);
int						ft_strcmp(const char *s1, const char *s2);
unsigned long long		ascii_to_ull(const char *str);

#endif
