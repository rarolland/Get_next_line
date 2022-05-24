/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarollan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:02:16 by rarollan          #+#    #+#             */
/*   Updated: 2022/05/23 11:08:52 by rarollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int		fd;
	char	*ligne;

	fd = open("test", O_RDONLY);
	while(1)
	{
		ligne = get_next_line(fd);
		if (ligne == NULL)
			break;
		printf("%s", ligne);
		free(ligne);
	}
	return (0);
}
