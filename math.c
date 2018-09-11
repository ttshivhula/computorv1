/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:43:21 by ttshivhu          #+#    #+#             */
/*   Updated: 2018/09/11 11:45:36 by ttshivhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computorv1.h>

static double	root(double n)
{
	double	lo;
	double	hi;
	double	mid;
	int		i;

	lo = 0;
	hi = n;
	i = -1;
	while (++i < 5000)
	{
		mid = (lo + hi) / 2;
		if (mid * mid == n)
			return mid;
		if (mid * mid > n)
			hi = mid;
		else
			lo = mid;
	}
	return mid;
}

static void		solve(double a, double b, double c, int exp)
{
	double x1;
	double	x2;

	x1 = (-b + root(b * b  - 4 * a * c)) / (2 * a);
	x2 = (-b - root(b * b  - 4 * a * c)) / (2 * a);
	if (exp == 2)
		printf("X1: %f X2: %f\n", x1, x2);
	else
	{
		x1 = (-c) / b;
		printf("X: %f\n", x1);
	}
}

void			ft_ans(double a, double b, double c, int exp)
{
	(exp == 2 || exp == 1) ? printf("Reduced form: ") : 0;
	if (exp == 2)
	{
		printf("%.3fx^2", a);
		printf("%+.3fx", b);
		printf("%+.3f = 0\n", c);
	}
	else if (exp == 1)
	{
		printf("%.3fx", b);
		printf("%+.3f = 0\n", c);
	}
	else
		printf("can't solve: %d exponents\n", exp);
	(exp == 2 || exp == 1) ? solve(a, b, c, exp) : 0;
}
