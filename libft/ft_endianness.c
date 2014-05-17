/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endianness.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 16:27:23 by gmange            #+#    #+#             */
/*   Updated: 2014/01/19 02:32:36 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** for Little endian, 2 will be stored as 0000 0000 0000 0010
** so, its first byte represent Zero value,
** but for Big endian, 2 will be stored as 0000 0010 0000 0000,
** so the first byte value will represent two(2) as value.
*/

/*
** results: 0 => machine is little endian
** results: 1 => machine is big endian
*/

char				ft_endianness(void)
{
	unsigned int	i;
	char			*c;

	i = 1;
	c = (char*)&i;
	return (!*c);
}
