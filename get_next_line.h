/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhendrik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:00:53 by rhendrik          #+#    #+#             */
/*   Updated: 2019/08/19 11:41:17 by rhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#include "libft/libft.h"
#include <stdio.h>
#define BUFF_SIZE 10

int get_next_line(const int fd, char **line);

#	endif
