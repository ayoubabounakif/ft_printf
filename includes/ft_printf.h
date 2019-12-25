/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:43:54 by aabounak          #+#    #+#             */
/*   Updated: 2019/12/25 15:01:02 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int					ft_printf(const char *format, ...);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_unsigned_itoa(size_t n);
char				*ft_strchr(const char *s, int c);
void				ft_putchar(int c);
void				ft_putnbr(int n);
void				ft_putstr(char *s);
void				ft_putunsignednbr(unsigned int n);
unsigned long long	ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strrev(char *str);
char				*ft_hex_55(int d);
char				*ft_hex_87(int d);
char				*ft_memory(unsigned long long d);
void				format_specifiers(va_list arg, char *traverse);
int					format_specifiers_condition(char *format, int i);
int					extra_condition(char *format, int i);
int					ft_escape(char *traverse);
char				ft_check(char *format);
int					ft_search(char *traverse);
void				ft_calculate(int size, char c);
int					ft_calculate_hex(int size, char c);
char				where_star(char *traverse);
char				*ft_fill_2(char *dst, char *src, int i, int c);
char				*ft_fill(va_list arg, char *dst, char *src, int c);
char				*fill(char *dst, char *src, int c);
void				ft_do(va_list arg, char *format, int i);
int					extra_condition(char *format, int i);
int					format_specifiers_condition(char *format, int i);
void				ft_call_min_width(va_list arg, char *traverse);
void				ft_call_zero_flag(va_list arg, char *traverse);
void				ft_call_negative_width(va_list arg, char *traverse);
void				ft_call_star_flag(va_list arg, char *traverse, int i);
void				ft_call_precision(va_list arg, char *traverse);
void				ft_call_min_precision(va_list arg, char *traverse);
void				ft_call_negative_star_flag(va_list arg, char *traverse);
void				ft_call_star_min_precision(va_list arg, char *trav, int i);
void				min_width_s(va_list arg, char *traverse);
void				min_width_c(va_list arg, char *traverse);
void				min_width_d_i(va_list arg, char *traverse);
void				min_width_u(va_list arg, char *traverse);
void				min_width_x_87(va_list arg, char *traverse);
void				min_width_x_55(va_list arg, char *traverse);
void				min_width_p(va_list arg, char *traverse);
void				min_width_percent(va_list arg, char *traverse);
void				zero_flag_s(va_list arg, char *traverse);
void				zero_flag_c(va_list arg, char *traverse);
void				zero_flag_d_i(va_list arg, char *traverse);
void				zero_flag_u(va_list arg, char *traverse);
void				zero_flag_x_87(va_list arg, char *traverse);
void				zero_flag_x_55(va_list arg, char *traverse);
void				zero_flag_percent(char *traverse);
void				star_flag_s(va_list arg, int i);
void				star_flag_c(va_list arg, int i);
void				star_flag_d_i(va_list arg, int i);
void				star_flag_u(va_list arg, int i);
void				star_flag_x_87(va_list arg, int i);
void				star_flag_x_55(va_list arg, int i);
void				star_flag_p(va_list arg, int i);
void				star_flag_percent(va_list arg, int i);
void				negative_star_flag_s(va_list arg);
void				negative_star_flag_c(va_list arg);
void				negative_star_flag_d_i(va_list arg);
void				negative_star_flag_u(va_list arg);
void				negative_star_flag_x_87(va_list arg);
void				negative_star_flag_x_55(va_list arg);
void				negative_star_flag_p(va_list arg);
void				negative_star_flag_percent(va_list arg);
void				negative_width_s(va_list arg, char *traverse);
void				negative_width_c(va_list arg, char *traverse);
void				negative_width_d_i(va_list arg, char *traverse);
void				negative_width_u(va_list arg, char *traverse);
void				negative_width_x_87(va_list arg, char *traverse);
void				negative_width_x_55(va_list arg, char *traverse);
void				negative_width_p(va_list arg, char *traverse);
void				negative_width_percent(char *traverse);
void				precision_s(va_list arg, char *traverse);
void				precision_c(va_list arg, char *traverse);
void				precision_d_i(va_list arg, char *traverse);
void				precision_u(va_list arg, char *traverse);
void				precision_x_87(va_list arg, char *traverse);
void				precision_x_55(va_list arg, char *traverse);
void				precision_p(va_list arg);
void				precision_percent(char *traverse);
void				min_precision_s(va_list arg, char *traverse);
void				min_precision_c(va_list arg, char *traverse);
void				min_precision_d_i(va_list arg, char *traverse);
void				min_precision_u(va_list arg, char *traverse);
void				min_precision_x_87(va_list arg, char *traverse);
void				min_precision_x_55(va_list arg, char *traverse);
void				min_precision_p(va_list arg, char *traverse);
void				min_precision_percent(char *traverse);
void				star_min_precision_s(va_list arg, char *trav, int i);
void				star_min_precision_c(va_list arg, char *trav, int i);
void				star_min_precision_d_i(va_list arg, char *trav, int i);
void				star_min_precision_u(va_list arg, char *trav, int i);
void				star_min_precision_x_87(va_list arg, char *trav, int i);
void				star_min_precision_x_55(va_list arg, char *trav, int i);
void				star_min_precision_p(va_list arg, int i);
void				star_min_precision_percent(va_list arg, int i);
void				neg_calcul(va_list arg, char *first, char *second);
void				neg_calcul_u(va_list arg, char *first, char *second);
void				neg_calcul_x_55(va_list arg, char *first, char *second);
void				neg_calcul_x_87(va_list arg, char *first, char *second);
void				star_neg_calcul(va_list arg, int first, int second);
void				star_neg_calcul_u(va_list arg, int first, int second);
void				star_neg_calcul_x_55(va_list arg, int first, char second);
void				star_neg_calcul_x_87(va_list arg, int first, char second);
void				calcul(va_list arg, char *first, char *second, int star_i);
void				calcul_u(va_list arg, char *fir, char *sec, int star_i);
void				helper_calcul_u_2(unsigned int varg, char *sec, int s);
void				calcul_x_55(va_list arg, char *fir, char *sec, int s_ind);
void				helper_calcul_x_55_2(unsigned int varg, char *sec, int s);
void				calcul_x_87(va_list arg, char *fir, char *sec, int s_ind);
void				helper_calcul_x_87_2(unsigned int varg, char *sec, int s);
void				min_precision_s_2(char *varg, char *fir, char *sec);
void				min_precision_s_3(char *varg, char *fir, char *sec);
void				star_calcul(va_list arg, int fir, int sec);
void				star_calcul_u(va_list arg, int fir, int sec);
void				star_calcul_x_55(va_list arg, int fir, char sec);
void				star_calcul_x_87(va_list arg, int fir, char sec);
void				star_min_precision_s_1(char *varg, int fir, int sec, int i);
void				star_min_precision_s_2(char *varg, int fir, int sec);
void				star_min_precision_s_3(char *varg, int fir, int sec);
#endif
