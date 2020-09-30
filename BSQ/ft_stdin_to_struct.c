
#include "bsq.h"

int		ft_read_buff(t_file *file)
{
    ssize_t bytes;
    char	str[280000];

	file->file_size = 0;
	file->buff = malloc(sizeof(char) * (280000 + 1));
    while ((bytes = read(0, str, 280000)))
    {
        strncat(file->buff, str, bytes);
		file->file_size += bytes;
    }
	return (1);
}

int    ft_param_line(t_file *file)
{
    int i;
    int j;
    char *nbr;

	i = 0;
    j = 0;
	if (file->buff == NULL)
		return (0);
    while (file->buff[i] != '\n')
        i++;
    file->full = file->buff[--i];
    file->obstacle = file->buff[--i];
    file->empty = file->buff[--i];
    while (j < i)
        j++;
    if (!(nbr = malloc(sizeof(char) * (j + 1))))
        return (0);
    i = 0;
    while (i < j)
    {
        nbr[i] = file->buff[i];
        i++;
    }
    nbr[i] = '\0';
    file->nb_lines = atoi(nbr);
	free(nbr);
	if (file->nb_lines == 0)
		return (0);
	return (1);
}

int		ft_stdin_to_struct(t_file *file)
{
	int i;
	int c;

	i = 0;
	c = 0;
	file->is_ok = TRUE;
	file->name = NULL;
    file->fd = 0;
    if (ft_read_buff(file) == 0)
		return (0);
    if (ft_param_line(file) == 0)
		return (0);
	while (file->buff[i] != '\n')
		i++;
	i++;
	file->buff = file->buff + i;
	file->param_size = i - 1;
	file->file_size -= file->param_size + 1;
	i = 0;
	while (file->buff[i] != '\n')
		i++;
	file->nb_col = i + 1;
	if (file->nb_col <= 1)
		return (0);
//	printf("empty 	 	--> %c\n", file->empty);
//	printf("full  	 	--> %c\n", file->full);
//	printf("obstacle 	--> %c\n", file->obstacle);
//	printf("param size 	--> %d\n", file->param_size);
//	printf("nb_lines	--> %d\n", file->nb_lines);
//	printf("nb_col		--> %d\n", file->nb_col);
//	printf("file.size	--> %d\n", file->file_size);
//   	printf("| buffer |\n%s\n", file->buff);
   	return (1);
}









