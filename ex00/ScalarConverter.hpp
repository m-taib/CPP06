/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaib <mtaib@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:27:58 by mtaib             #+#    #+#             */
/*   Updated: 2023/11/12 19:08:15 by mtaib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <limits.h>
#include <stdlib.h>
#include "float.h"

class UnkownType : public std::exception
{
		public :
			const char	*what() const throw()
			{
				return ("UNKOWN TYPE");
			}
};

class ScalarConverter
{
	public :
		~ScalarConverter();
		
		static void	convert(std::string type);

	private :
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter& operator=(const ScalarConverter& rhs);
};

int	isChar(const std::string& type);	
int	isInt(const std::string& type);	
		
void	castChar(std::string& type);
void	castInt(std::string& type);
void	castFloat(double& nb);
void	castDouble(double& nb);

int	isLiteral(const std::string& type);
std::string getLiteral(std::string& type, char c);
#endif
