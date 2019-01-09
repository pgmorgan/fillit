/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorgan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:28:20 by pmorgan-          #+#    #+#             */
/*   Updated: 2018/12/03 14:38:46 by pmorgan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (!*s1 && !*s2)
		return (1);
	else if (*s1 != *s2)
		return (0);
	return (ft_strequ(++s1, ++s2));
}
