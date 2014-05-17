/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osoliver <osoliver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 16:05:27 by osoliver          #+#    #+#             */
/*   Updated: 2014/03/05 16:05:28 by osoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# define COSX	maths->cosx
# define SINX	maths->sinx
# define COSY	maths->cosy
# define SINY	maths->siny
# define COSZ	maths->cosz
# define SINZ	maths->sinz
# define PROD1	maths->prod1
# define PROD2	maths->prod2

# define AA	t_matrix[0][0]
# define BB	t_matrix[0][1]
# define CC	t_matrix[0][2]
# define DD	t_matrix[1][0]
# define EE	t_matrix[1][1]
# define FF	t_matrix[1][2]
# define GG	t_matrix[2][0]
# define HH	t_matrix[2][1]
# define II	t_matrix[2][2]

typedef struct			s_maths
{
	float				cosx;
	float				sinx;
	float				cosy;
	float				siny;
	float				cosz;
	float				sinz;
	float				prod1;
	float				prod2;
}						t_maths;

#endif
