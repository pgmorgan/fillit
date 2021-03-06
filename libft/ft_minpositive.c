/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minpositive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:32:01 by pmorgan-          #+#    #+#             */
/*   Updated: 2019/01/02 14:34:48 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_minpositive(int n1, int n2)
{
	if (n1 < 0 && n2 < 0)
		return (0);
	if (n1 < 0 && n2 >= 0)
		return (n2);
	if (n1 >= 0 && n2 < 0)
		return (n1);
	return (n1 <= n2) ? n1 : n2;
}
