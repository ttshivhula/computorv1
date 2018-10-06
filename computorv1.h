/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:40:20 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/10/05 09:53:04 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include <string.h>
# include <glibft.h>
# include <stdio.h>
# include <ctype.h>
# define ABS(x) (((x) < 0) ? -(x) : (x))

typedef	struct			s_values
{
	double				value;
	int					exponent;
	struct s_values		*next;
}						t_values;

void			read_values(char *s, t_values **values, t_garbage **gb);
void					add_val(t_values **head,
		double value, int exponent, t_garbage **gb);
void					clean(t_values **head, t_garbage **gb);
void					ft_ans(double a, double b, double c, int exp);

#endif
