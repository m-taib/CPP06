/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:34:27 by mtaib             #+#    #+#             */
/*   Updated: 2023/11/12 20:55:38 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
	(void)rhs;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{

}

int	isLiteral(const std::string& type)
{
	if (!type.compare("+inf") || !type.compare("-inf") 
			|| !type.compare("+inff") || !type.compare("-inff") 
			|| !type.compare("nan")   || !type.compare("nanf")
			|| !type.compare("inf") || !type.compare("inff")) 
		return (1);
	return (0);
}

int		isChar(const std::string& type)
{
	return (type.length() == 1 && !std::isdigit(type[0]));
}

int		isInt(const std::string& type)
{
	int		i;
	
	i = 0;
	if (type[0] && (type[0] == '-' || type[0] == '+'))
		i++;
	if (!type[i])
		return (0);
	while (type[i])
		if (!std::isdigit(type[i++]))
			return (0);
	return (1);
}

std::string getLiteral(const std::string& type, char c)
{
	if (c == 'f')
	{
		if (type == "-inf")
			return "-inff";
		else if (type == "+inf" || type == "inf")
			return "+inff";
		else if (type == "nan")
			return "nanf";
		else
			return type;
	}
	else
	{
		if (type == "-inff")
			return "-inf";
		else if (type == "+inff" || type == "inff")
			return "+inf";
		else if (type == "nanf")
			return "nan";
		else
			return type;
	}
}

void	castChar(std::string& type)
{
	char 	c;
	
	c = type[0];
	if (!std::isprint(c))
		std::cout << "char: Non diplayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f"<< std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	castInt(std::string& type)
{
	long 	nb;
	
	nb = std::atol(type.c_str());
	if (std::isprint(nb) && (nb >= INT_MIN && nb <= INT_MAX))
		std::cout << "char: '" << static_cast<char>(nb) << "'" <<  std::endl;
	else if (nb > 127 || nb < 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non diplayable" << std::endl;
	if (nb >= INT_MIN && nb <= INT_MAX)
		std::cout << "int: " << nb << std::endl;
	else
		std::cout << "int: impossible" <<  std::endl;
	std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(nb) << ".0" << std::endl;
}

void	castDouble(double& nb)
{
	std::cout << "double: " << nb << std::endl;
	if (std::isprint(nb))
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	else if (nb < INT_MIN || nb > INT_MAX)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non diplayable" << std::endl;
	if (nb >= INT_MIN && nb <= INT_MAX)
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
	else
		std::cout << "int: impossible" <<  std::endl;
	std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
}


void	castFloat(double& nb)
{
	float 	n;

	n = static_cast<float>(nb);
	std::cout << "float: " << n << "f" << std::endl;
	std::cout << "double: " << nb << std::endl;
	if (n >= INT_MIN && n <= INT_MAX)
		std::cout << "int: " << static_cast<int>(n) << std::endl;
	else
		std::cout << "int: impossible" <<  std::endl;
	if (std::isprint(n))
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else if (n < INT_MIN || n > INT_MAX)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non diplayable" << std::endl;
}

int		checkPrec(std::string& type)
{
	int		i;

	i = -1;
	while (type[++i])
		if (type[i] == '.')
			return (1);
	return (0);
}

void	printLiteral(const std::string& type)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << getLiteral(type, 'f') << std::endl;
	std::cout << "double: " << getLiteral(type, 'd') << std::endl;
}

void	ScalarConverter::convert(std::string type)
{
	char	*str;
	double	nb;

	nb = strtod(type.c_str(), &str);
	if (isLiteral(type))
	{
		printLiteral(type);
		return ;
	}
	if (isChar(type))
		castChar(type);	
	else if (isInt(type))
		castInt(type);
	else if (checkPrec(type) && str[0] == 'f' && !str[1])
		castFloat(nb);
	else if (checkPrec(type) && !str[0])
		castDouble(nb);
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
