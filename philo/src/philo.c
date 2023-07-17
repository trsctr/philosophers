/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:15:35 by oandelin          #+#    #+#             */
/*   Updated: 2023/07/17 16:10:54 by oandelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_settings	*settings;

	if (argc < 5 || argc > 6)
	{
		printf("pls gief argumenz");
		return (0);
	}
	settings = init_settings();
	if (!settings)
	{
		printf("fail\n");
		return (0);
	}
	if (save_settings(settings, argc, argv) < 0)
	{
		free(settings);
		printf("fail\n");
		return (0);
	}
}
