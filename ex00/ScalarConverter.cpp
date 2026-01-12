/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:21:01 by amaury            #+#    #+#             */
/*   Updated: 2026/01/12 08:50:49 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(std::string input) {convert(input);}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
    (void)other;
    return (*this);
}

void    ScalarConverter::convert(std::string input) {
    bool specialValue = false;
    long double value = 0;
    
    if (input == "-inff" || input ==  "+inff" || input == "nanf") {
        specialValue = true;
    }
    if (input == "-inf" || input ==  "+inf" || input == "nan") {
        specialValue = true;
        input += "f";
    }
    
    if (specialValue == false) {
        try {
            if (input.find('.') != std::string::npos && input.find('.', input.find('.') + 1) != std::string::npos) {
                throw std::invalid_argument("multi [.] found !");
            }
            if (input.find('.') == 0 || input.find('.') == input.size() - 1) {
                throw std::invalid_argument("bad pos for character [.] !");
            }
            
            if (input.find('f') != std::string::npos && input.find('f', input.find('f') + 1) != std::string::npos) {
                throw std::invalid_argument("multi [f] found !");
            }
            if (input.find('f') != input.size() - 1 && input.find('f') != std::string::npos) {
                throw std::invalid_argument("bad pos for character [f] !");
            }
            
            if (specialValue == false && input.size() != 1 && input[input.size() - 1] == 'f')
                input.erase(input.size() - 1);
            if (input.size() == 1 && !isdigit(input.c_str()[0]))
                value = static_cast<int>(input.c_str()[0]);
            else {
                std::stringstream ss(input);
                ss.precision(1);
                ss >> value;
                if (value > 1e6L || value < -1e6L)
                    std::cout << std::scientific << std::setprecision(1);
                else
                    std::cout << std::fixed << std::setprecision(1);
                if (ss.fail() || !ss.eof()) {
                    std::cerr << "Invalid Input" << std::endl;
                    return ;
                }
            }
        }
        catch (std::invalid_argument const& e) {
            std::cerr << "std::invalid_argument::what(): " << "'" << e.what() << "'" << std::endl;;
            return ;
        }
        catch (std::out_of_range const& e) {
            std::cerr << "std::out_of_range::what(): " << "'" << e.what() << "'" << std::endl;
            return ;
        }
    }
    
    if (value < 0 || value > 127 || specialValue)                   {std::cout << "char: impossible" << std::endl;}
    else if      (!isprint(value))                                  {std::cout << "char: Non displayable" << std::endl;}
    else                                                            {std::cout << "char: " << static_cast<char>(value) << std::endl;}
    
    if (specialValue || value > 2147483647 || value < -2147483648)  {std::cout << "int: impossible" << std::endl;}
    else                                                            {std::cout << "int: " << static_cast<int>(value) << std::endl;}
        
    if      (specialValue == true)                          {std::cout << "float: " << input << std::endl;}
    else if (value > std::numeric_limits<float>::max())     {std::cout << "float: impossible" << std::endl;}
    else if (value < -std::numeric_limits<float>::max())    {std::cout << "float: impossible" << std::endl;}
    else                                                    {std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;}
    
    if (specialValue == true)                               {std::cout << "double: " << input.erase(input.size() - 1) << std::endl;}
    else if (value > std::numeric_limits<double>::max())    {std::cout << "double: impossible" << std::endl;}
    else if (value < -std::numeric_limits<double>::max())   {std::cout << "double: impossible" << std::endl;}
    else                                                    {std::cout << "double: " << static_cast<double>(value) << std::endl;}
}