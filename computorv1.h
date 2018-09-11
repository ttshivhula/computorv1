/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:40:20 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/09/11 11:45:21 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>

typedef	struct			s_values
{
	double				value;
	unsigned int		exponent;
	struct s_values		*next;
}						t_values;

void					read_values(char *s, t_values **values);
void					add_val(t_values **head,
		double value, int exponent);

void					add_val(t_values **head, double value, int exponent);
void					clean(t_values **head);
void					ft_ans(double a, double b, double c, int exp);

#endif
