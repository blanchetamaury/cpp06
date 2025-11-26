/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:21:01 by amaury            #+#    #+#             */
/*   Updated: 2025/11/26 09:36:20 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(): value(0), specialValue(false) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(std::string input): value(0), specialValue(false) {setInput(input);}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    value = other.value;
    specialValue = other.specialValue;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
    if (this != &other) {
        value = other.value;
        specialValue = other.specialValue;
    }
    return (*this);
}

void    ScalarConverter::setInput(std::string input) {
    parsingValue(input);
    if (specialValue == false && input.size() != 1 && input[input.size() - 1] == 'f')
        input.erase(input.size() - 1);
    std::stringstream ss(input);
    ss >> value;
    if (input.size() == 1 && isascii(input[0]))
        value = static_cast<long double>(input[0]);
    else if ((ss.fail() || !ss.eof()) && specialValue == false) {
        std::cerr << "Invalid Input" << std::endl;
        return ;
    }
    stringToChar();
    stringToInt();
    if (value > 1e6L || value < -1e6L)
        std::cout << std::scientific << std::setprecision(1);
    else
        std::cout << std::fixed << std::setprecision(1);
    stringTofloat(input);
    stringToDouble(input);
}

void    ScalarConverter::stringToChar()
{
    if      (!isprint(static_cast<char>(value)) || specialValue)    {std::cout << "char: Non displayable" << std::endl;}
    else if (value < 0 || value > 127)                              {std::cout << "char: Non displayable" << std::endl;}
    else                                                            {std::cout << "char: " << static_cast<char>(value) << std::endl;}
}

void    ScalarConverter::stringToInt()
{
    if (specialValue || value > 2147483647 || value < -2147483648)  {std::cout << "int: Non displayable" << std::endl;}
    else                                                            {std::cout << "int: " << static_cast<int>(value) << std::endl;}
}

void    ScalarConverter::stringTofloat(std::string input)
{
    if      (specialValue == true)                          {std::cout << "float: " << input << std::endl;}
    else if (value > std::numeric_limits<float>::max())     {std::cout << "float: Non displayable" << std::endl;}
    else if (value < -std::numeric_limits<float>::max())    {std::cout << "float: Non displayable" << std::endl;}
    else                                                    {std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;}
}

void    ScalarConverter::stringToDouble(std::string input)
{
    if (specialValue == true)                               {std::cout << "double: " << input.erase(input.size() - 1) << std::endl;}
    else if (value > std::numeric_limits<double>::max())    {std::cout << "double: Non displayable" << std::endl;}
    else if (value < -std::numeric_limits<double>::max())   {std::cout << "double: Non displayable" << std::endl;}
    else                                                    {std::cout << "double: " << static_cast<double>(value) << std::endl;}
}

void    ScalarConverter::parsingValue(std::string &input) {
    if (input == "-inff" || input ==  "+inff" || input == "nanf") {
        specialValue = true;
    }
    if (input == "-inf" || input ==  "+inf" || input == "nan") {
        specialValue = true;
        input += "f";
    }
}