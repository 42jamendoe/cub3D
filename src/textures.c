/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:00:10 by jamendoe          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:14 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"
#include "../includes/libft.h"

void	ft_load_image(t_cub3d *cub3d, t_img *info, char *path)
{
	info->ptr = mlx_xpm_file_to_image (cub3d->mlx, path, \
	&info->width, &info->height);
	if (!info->ptr)
		ft_safe_exit (cub3d, "CAN'T CREATE IMAGE");
	if (info->width != TEXTURE_WIDTH || info->height != TEXTURE_HEIGHT)
		ft_safe_exit (cub3d, "IMAGE_SIZE");
	info->addr = mlx_get_data_addr (info->ptr, &info->bpp, \
	&info->size_line, &info->endian);
	if (!info->addr)
		ft_safe_exit (cub3d, "CAN'T CREATE addr");
}

void	ft_load_textures(t_cub3d *cub3d)
{
	ft_load_image(cub3d, &cub3d->texture->img_no, cub3d->texture->north);
	ft_load_image(cub3d, &cub3d->texture->img_we, cub3d->texture->west);
	ft_load_image(cub3d, &cub3d->texture->img_so, cub3d->texture->south);
	ft_load_image(cub3d, &cub3d->texture->img_ea, cub3d->texture->east);
}

void	ft_test_textures(t_cub3d *cub3d)
{
	int	fd;

	if (cub3d->texture->north == NULL || cub3d->texture->south == NULL \
		|| cub3d->texture->east == NULL || cub3d->texture->west == NULL)
		ft_safe_exit(cub3d, ERR_SCENE_TILE);
	if (!cub3d->texture->has_c || !cub3d->texture->has_f)
		ft_safe_exit(cub3d, ERR_RGB_MISS);
	fd = open (cub3d->texture->north, O_RDWR);
	if (fd < 1)
		ft_safe_exit(cub3d, ERR_SCENE_TILE);
	fd = open (cub3d->texture->south, O_RDWR);
	if (fd < 1)
		ft_safe_exit(cub3d, ERR_SCENE_TILE);
	fd = open (cub3d->texture->east, O_RDWR);
	if (fd < 1)
		ft_safe_exit(cub3d, ERR_SCENE_TILE);
	fd = open (cub3d->texture->west, O_RDWR);
	if (fd < 1)
		ft_safe_exit(cub3d, ERR_SCENE_TILE);
}
