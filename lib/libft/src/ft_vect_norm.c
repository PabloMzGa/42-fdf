/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:51:16 by pablo             #+#    #+#             */
/*   Updated: 2025/02/07 16:15:56 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Normalizes a vector.
 *
 * This function takes a vector and its dimension, and returns a normalized
 * version of the vector. Normalization is done by dividing the vector by its
 * magnitude.
 *
 * @param vect The vector to be normalized.
 * @param d The dimension of the vector.
 * @return A pointer to the normalized vector.
 * @note The caller is responsible of freeing the returned vector.
 */
double *ft_vect_norm(double  *vect, size_t d)
{
	return (ft_vect_div(vect, ft_vect_magn(vect, d), d));
}
