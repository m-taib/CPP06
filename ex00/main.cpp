/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:18:30 by mtaib             #+#    #+#             */
/*   Updated: 2023/11/12 18:17:41 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	try
	{
		ScalarConverter::convert(av[1]);
	}
	catch (const std::exception& exp)
	{
		std::cout << exp.what() << std::endl;
	}
	return (0);
}
