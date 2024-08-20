/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willem <willem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:11:01 by ischmutz          #+#    #+#             */
/*   Updated: 2024/08/19 21:18:06 by willem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		int	i = 0;
		while (argv[++i])
		{
			int j = -1;
			while (argv[i][++j])
				argv[i][j] = std::toupper(argv[i][j]);
			std::cout << argv[i];
			if ((i + 1) == argc)
				continue ;
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;

    
}

// for (int i = 1; argv[i]; i++) {
//     for (int j = 0; argv[i][j]; j++)
//         argv[i][j] = std::toupper(argv[i][j]);
//     std::cout << argv[i];
//     if ((i + 1) == argc)
//         continue ;
//     std::cout << " ";
// }
// std::cout << std::endl;