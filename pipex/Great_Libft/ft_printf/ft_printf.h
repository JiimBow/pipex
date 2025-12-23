/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:42:11 by jodone            #+#    #+#             */
/*   Updated: 2025/10/28 09:36:11 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//includes
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//functions
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
void	ft_putnbr_base(int nbr, char *base, int *count);
void	ft_uputnbr_base(unsigned int nbr, char *base, int *count);
char	*ft_itoax(unsigned long nb, int is_low, int *count);
void	ft_putstr_print(char *s, int fd, int *count);
void	ft_putchar_print(char c, int fd, int *count);
void	ft_ulputnbr_ptr(unsigned long nbr, int *count);
int		ft_printf(const char *fmt, ...);

#endif