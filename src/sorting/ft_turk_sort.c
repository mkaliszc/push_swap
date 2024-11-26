/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:48:20 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/26 02:06:14 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* pour le turk sort on va prendre un element de la stack_b, trouver l'espace qui lui correspond a l'aode des index 
(chercher l'index grand le plus proche et l'index petit le plus proche), puis tout remettre en ordre avec l'index 0 en head*/

void	ft_turk_sort(t_stack **stack_a, t_stack **stack_b, t_cost *cost)
{
	t_stack	*best_element;
	t_stack	*element;
	int		full_rotation;

	while (*stack_b)
	{
		element = *stack_b;
		full_rotation = 0;
		cost->best = INT_MAX;
		while (full_rotation < ft_stack_length(stack_b))
		{
			/*Compter le ombre de rotations qu'il faut faire dan A et dans B (chercher une methode avec les reverse et rr ?)
			puis ajouter l'addition dans le total_cost
			si le total est inferieur au best mettre a jour le best element et le best
			puis avancer dans la stack*/
		}
		// rotate and push de B vers A
	}
}
