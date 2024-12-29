/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heechoi <heechoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:37:10 by heechoi           #+#    #+#             */
/*   Updated: 2024/12/13 21:39:04 by heechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

typedef char	t_bool;

typedef struct s_ident
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*c_color;
	char	*f_color;
}		t_ident;

typedef struct s_info
{
	char		**map;
	int			row;
	int			col;
	t_ident		ident;
}		t_info;

#endif