/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:41:44 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/11 14:53:17 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

/**
 * @brief Extracts a substring from the input save string after the first \n.
 *
 * @param save	 The input string from which to extract a substring.
 * @return char* A dynamically allocated string containing the substring
 * 				 after the first newline, or NULL if memory allocation fails.
 */

char	*get_save(char *save)
{
	char	*new_save;
	size_t	i;
	int		j;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			break ;
		i++;
	}
	new_save = malloc(((ft_strlen(save) - i) + 1) * sizeof(char));
	if (new_save == NULL)
		return (NULL);
	j = 0;
	while (i++ < ft_strlen(save))
	{
		new_save[j] = save[i];
		j++;
	}
	new_save[j] = '\0';
	free(save);
	return (new_save);
}
/**
 * @brief Concatenates the save string with the content of the buffer.
 *
 * @param save The existing save string to be concatenated.
 * @param buffer The buffer containing additional data.
 * @param byte_read The number of bytes read from the buffer.
 * @return char* A dynamically allocated string containing the
 * 				 concatenated result, or NULL if memory allocation fails.
 */

char	*update_save(char *save, char *buffer, int byte_read)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	if (!save || !buffer)
		return (NULL);
	while (save[i])
		i++;
	result = (char *)malloc((i + byte_read + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	j = 0;
	while (save[++i])
		result[i] = save[i];
	while (buffer[j])
		result[i++] = buffer[j++];
	result[i] = '\0';
	if (save != NULL)
	{
		free(save);
		save = NULL;
	}
	return (result);
}
/**
 * @brief Reads a line from a file descriptor and updates the save string.
 *
 * @param save A string containing the content read from the file descriptor.
 * @param fd The file descriptor to read from.
 * @return char* A dynamically allocated string containing the updated save
 * 				 string after reading from the file descriptor,
 * 				 or NULL if an error occurs or if memory allocation fails.
 */

char	*get_line(char *save, t_action **action, int byte_read, char *buffer)
{
	while (byte_read > 0)
	{
		byte_read = read(0, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(save);
			free(buffer);
			return (NULL);
		}
		if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		save = update_save(save, buffer, byte_read);
		if (ft_strchr(save, '\n'))
		{
			if (add_action(save, action))
				save = get_save(save);
			else
			{
				free(save);
				return (NULL);
			}
		}
	}
	return (save);
}

/**
 * @brief Reads a line from a file descriptor and returns the line.
 *        (and save the extra data in a static char *)
 * @param fd The file descriptor to read from.
 * @return char* A dynamically allocated string containing the line from the
 *               file, or NULL if the end of the file is reached or an error
 *               occurs.
 */

t_bool	get_next_line(t_action **action)
{
	char	*save;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (false);
	save = ft_calloc(1, 1);
	if (!save)
		return (false);
	save = get_line(save, action, 1, buffer);
	if (buffer != NULL)
		free(buffer);
	if (!save)
		return (false);
	if (save)
	{
		free(save);
		save = NULL;
	}
	return (true);
}
