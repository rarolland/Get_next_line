/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarollan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:58:38 by rarollan          #+#    #+#             */
/*   Updated: 2022/05/23 15:17:50 by rarollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* cherche une nouvelle ligne dans la ligne retenu */

int	found_newline(t_list *stock)
{
	int		i;
	t_list	*current;

	if (!stock)
		return (0);
	current = ft_lst_get_last(stock);
	i = 0;
	while (current->content[i])
	{
		if (current->content == '\n')
			return (1);
		i++;
	}
	return (0);	
}

t_list	*ft_lst_get_last(t_list *stock)
{
	t_list	*current;

	current = stock;
	while (current && current->next)
		current = current ->next;
	return (current);
}

void	genere_ligne(char **ligne, t_list *stock)
{
	int	i;
	int	len;

	len = 0;
	while (stock)
	{
		i = 0;
		while (stock->content[i])
		{
			if (stock->content[i] == '\n')
			{
				len++;
				break;
			}
			len++;
			i++;
		}
		stock = stock->next;
	}
	*ligne = malloc(sizeof(char) * (len + 1));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_stock(t_list **stock)
{
	t_list	*current;
	t_list	*next;

	current = stock;
	while (current->content)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
} 
