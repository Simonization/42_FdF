/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slangero <slangero@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:02:09 by slangero          #+#    #+#             */
/*   Updated: 2024/07/04 18:16:37 by slangero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	fd = open("one_line_no_nl.txt", O_RDONLY);
	line = NULL;
	line = get_next_line(fd);
	i = 0;
	while (i++ < 10)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	return (0);
}

// int main()
// {
//     // Open the file "test.txt" in read mode
//     FILE *fp = fopen("test.txt", "r");
//     // Read the first character from the file
//     int ch = getc(fp);
// 
//     // Loop until the end of the file is
//     // reached
//     while (ch != EOF) {
//         /* display contents of file on screen */
//         putchar(ch);
// 
//         // Read the next character from the file
//         ch = getc(fp);
//     }
//
//     // Check if the end-of-file indicator is
//     // set for the file
//     if (feof(fp))
//         printf("\n End of file reached.");
//     else
//         printf("\n Something went wrong.");
//
//     // Close the file
//     fclose(fp);
//
//     // Wait for a keypress
//     getchar();
//     return 0;
// }