#include "../includes/cub3D.h"

/*
    ft_exit va etre appele par le hook numero 17 (clic sur la croix)
*/

int	ft_exit(t_data *data)
{
	free_all(data);
	exit(0);
	return (0);
}

/*
    Cette fonction indique a notre structure quel touche "utile" est pressee
    (ex: rot_left => le personnage effectue une rotation vers la gauche)
    /!\ A CHANGER POUR CLAVIER QWERTY /!\
*/

int	key_pressed(int key, t_data *data)
{
	if (key == 65307)
		ft_exit(data);
	else if (key == 122)
		data->move_forward = 1;
	else if (key == 115)
		data->move_back = 1;
	else if (key == 100)
		data->move_right = 1;
	else if (key == 113)
		data->move_left = 1;
	else if (key == 65361)
		data->rot_left = 1;
	else if (key == 65363)
		data->rot_right = 1;
	else
		return (0);
	return (1);
}

/*
    On initialise les hook : touche pressee et clic sur la croix
*/

void	keyboard(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_pressed, data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
}
