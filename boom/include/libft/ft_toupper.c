/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arphueng <arphueng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:06:17 by arphueng          #+#    #+#             */
/*   Updated: 2024/08/31 17:34:33 by arphueng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int n)
{
	if (n >= 'a' && n <= 'z')
		return (n - 32);
	return (n);
}
