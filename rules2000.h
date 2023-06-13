/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2000.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:26:32 by alex              #+#    #+#             */
/*   Updated: 2023/06/13 13:36:57 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES2000_H
# define RULES2000_H

void	swap(int *tab, int size);
void	swap_a(int *a, int size, int isTest);
void	swap_b(int *b, int size, int isTest);
void	swap_ab(int *a, int *b, int size, int isTest);

void	push(int *start, int *end, int *size_start, int *size_end);
void	push_a(int *a, int *b, int *size_a, int *size_b, int isTest);
void	push_b(int *a, int *b, int *size_a, int *size_b, int isTest);

void	rotate(int *stack, int size);
void	rotate_a(int *a, int size, int isTest);
void	rotate_b(int *b, int size, int isTest);
void	rotate_ab(int *a, int *b, int size_a, int size_b, int isTest);

void	reverse_rotate(int *stack, int size);
void	reverse_rotate_a(int *a, int size, int isTest);
void	reverse_rotate_b(int *b, int size, int isTest);
void	reverse_rotate_ab(int *a, int *b, int size_a, int size_b, int isTest);

#endif
