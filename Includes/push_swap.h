/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:55:13 by udumas            #+#    #+#             */
/*   Updated: 2024/01/04 19:51:55 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef T_PILE
#  define T_PILE

typedef struct s_pile
{
	void	*next;
	void	*prec;

	long	number;
	int		rank;
	int		group;
	int		index;

	long	link;
	int		linkrank;
	int		linkposition;

	int		steps;
	int		position;
}			t_pile;

# endif

// main

void		last_check(t_pile **a_pile);
void		launch_algo(t_pile **a_pile, t_pile **b_pile);
t_pile		*check_and_parse(char **av, int ac);
int			main(int ac, char **av);

// check

int			count_numbers(char **av);
int			is_digit_space(char **av);
int			check_double(t_pile **init);
int			check_pile(t_pile *a_pile);

// parse

t_pile		*parse(t_pile **init, char **av, int size);
int			create_chain_list(t_pile **start, char *str);
int			ft_extract(long *number, char *str);

// instructions

void		swap(t_pile **a_pile, char *instruct, int checker);
void		push(t_pile **push, t_pile **receive, char *instruct, int checker);
void		swap_distribute(t_pile **a_list, t_pile **b_list, char *instruct,
				int checker);
void		push_distribute(t_pile **a_list, t_pile **b_list, char *instruct,
				int checker);

// more_instructions

void		rotate(t_pile **to_rotate);
void		reverse_rotate(t_pile **to_rotate);
void		rotate_distribute(t_pile **a_list, t_pile **b_list, char *instruct,
				int checker);
void		reverse_rotate_distribute(t_pile **a_list, t_pile **b_list,
				char *instruct, int checker);

// set_up_algo

void		test_link(t_pile **node, t_pile *link);
void		calculate_steps(t_pile **a_pile, int size_b);
void		attribuate_link(t_pile **a_pile, t_pile **b_pile);
void		push_start(t_pile **a_pile, t_pile **b_pile);
void		particular_case(t_pile **a_pile, int status);

// algo_part1

void		rotate_both(t_pile **a_pile, t_pile **b_pile, t_pile *to_move);
void		reverse_rotate_both(t_pile **a_pile, t_pile **b_pile,
				t_pile *to_move);
void		set_a_pile(t_pile **a_pile, t_pile *to_move);
void		set_b_pile(t_pile **b_pile, t_pile *to_move);
void		push_a_to_b_order(t_pile **a_pile, t_pile **b_pile);

// algo_part2

void		attribuate_link_a(t_pile **a_pile, t_pile **b_pile);
void		calculate_steps2(t_pile **b_pile, int size_a);
void		set_a_pile2(t_pile **a_pile, t_pile *to_move);
void		set_for_groups(t_pile **a_pile, t_pile **b_pile, t_pile *cost_min);
void		push_b_to_a_order(t_pile **a_pile, t_pile **b_pile, int size);

// algo_part3

void		rotate_both2(t_pile **a_pile, t_pile **b_pile, t_pile *to_move);
void		reverse_rotate_both2(t_pile **a_pile, t_pile **b_pile,
				t_pile *to_move);
void		set_a_pile3(t_pile **a_pile, t_pile *to_move);
void		set_b_pile2(t_pile **b_pile, t_pile *to_move);
t_pile		*cheapest_cost2(t_pile *a_pile);
// utils

int			ft_lstsize(t_pile *lst);
void		ft_lstadd_front(t_pile **lst, t_pile *new);
void		ft_cleanpile(t_pile **s_pile);
t_pile		*cheapest_cost(t_pile *a_pile);
int			is_sorted(t_pile *a_pile);

// utils2

void		set_prec(t_pile *to_set);
void		set_rank(t_pile *to_set);
t_pile		*find_smallest_number(t_pile **pile);
t_pile		*get_biggest_number(t_pile **pile);

// utils3

t_pile		*ft_lstlast(t_pile *lst);
void		ft_lstadd_back(t_pile **lst, t_pile *new);
int			get_biggest_group(t_pile *pile);
void		test_link2(t_pile **node, t_pile *link);

// get_groups

int			get_groups(int index, int size_a);
void		initialize(t_pile **a_pile);
void		add_index_groups(t_pile **a_pile);
t_pile		*smallest_no_index(t_pile *a_pile);

// push_by_groups
void		push_by_groups(t_pile **a_pile, t_pile **b_pile);
int			smallest_group_check(t_pile *a_pile);
void		send_to_b_rotate(t_pile **a_pile, t_pile **b_pile);

// CHECKER ////////////////////////////////////////////////////////////////////

int			get_next_command(t_pile **a_pile, t_pile **b_pile);
void		clean(t_pile **a_pile, t_pile **b_pile);
int			ft_compare(t_pile **a_pile, t_pile **b_pile, char **line);

#endif