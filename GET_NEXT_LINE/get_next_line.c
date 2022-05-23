/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarollan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:49:46 by rarollan          #+#    #+#             */
/*   Updated: 2022/05/23 15:20:17 by rarollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static s_list	*stock = NULL;
	char			*ligne;
	int				lu;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &ligne, 0) < 0)
		return (NULL);
	lu = 1;
	ligne = NULL;
	// lire depuis fd et ajouter a la liste chainee
	read_and_stock(fd, &stock, &lu);
	if (stock == NULL)
		return (NULL);
	// extraire depuis stock a ligne 
	extract_ligne(stock, &ligne);
	// clean stock
	clean_stock(&stock);
	if (ligne[0] == '\0')
	{
		free(stock);
		stock = NULL;
		free(ligne);
		return (NULL);
	}
	return (ligne);
}

void	read_and_stock(int fd, t_list **stock, int *lu_ptr)
{
	char	*buff;

	while (!found_newline(*stock) && *lu_ptr != 0);
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return;
		*lu_ptr = (int)read(fd, buff, BUFFER_SIZE);
		if ((*stock == NULL && *lu_ptr == 0) || *lu_ptr == -1)
		{
			free(buff);
			return;
		}
		buff[*lu_ptr] = '\0';
		add_to_stock(stock, buff, *lu_ptr);
		free(buff);
	}
}

void	add_to_stock(t_list **stock, char *buff, int lu)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!newnode)
		return;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (lu + 1));
	if (!new_node->content)
		return;
	i = 0;
	while (buff[i] && i < lu)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content = '\0';
	if (*stock == NULL)
	{
		*stock = new_node;
		return;
	}
	last = ft_lst_get_last(*stock);
	last = new_node;
}

void	extract_ligne(t_list *stock, char **ligne)
{
	int	i;
	int	j;

	if (!stock)
		return;
	genere_ligne(ligne, stock);
	if (!ligne)
		return;
	j = 0;
	while (stock)
	{
		i = 0;
		while (stock->content[i])
		{
			if (stock->content[i] == '\n')
			{
				(*ligne)[j++] = stock->content[i];
				break;
			}
			(*ligne)[j++] = stock->content[i++];
		}
		stock = stock->next;
	}
	(*ligne)[j] = '\0';
}

void	clean_stock(t_list **stock)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	if (!stock)
		return;
	clean_node = malloc(sizeof(t_list));
	if (!clean_node)
		return;
	clean_node->next = NULL;
	last = ft_lst_get_last(*stock)
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * (ft_strlen(last->content) - i) + 1);
	if(!clean_node)
		return;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stock(*stock);
	*stock = clean_node;
}
