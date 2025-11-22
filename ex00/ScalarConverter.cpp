/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:21:01 by amaury            #+#    #+#             */
/*   Updated: 2025/11/22 15:21:33 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(): value(0), status(0), specialValue(false) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(std::string input): value(0), status(0), specialValue(false) {setInput(input);}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    value = other.value;
    status = other.status;
    specialValue = other.specialValue;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
    if (this != &other) {
        value = other.value;
        status = other.status;
        specialValue = other.specialValue;
    }
    return (*this);
}

void    ScalarConverter::setInput(std::string input) {
    specialValue = false;
    status = parsingValue(input);
    if (status == -1) {
        std::cerr << "Invalid Input" << std::endl;
        return ;
    }
    if (status == 0)
        value = static_cast<long double>(input[0]);
    else
        static_cast<std::stringstream>(input) >> value;
    stringToChar();
    stringToInt();
    stringTofloat(input);
    stringToDouble(input);
}

void    ScalarConverter::stringToChar() {
    if (!isprint(static_cast<char>(value)) || specialValue == true || value > 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(value) << std::endl;
}

void    ScalarConverter::stringToInt() {
    if (specialValue == true || value > 2147483647 || value < -2147483648)
        std::cout << "int: Non displayable" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void    ScalarConverter::stringTofloat(std::string input) {
    if (specialValue == true && status == 2)
        std::cout << "float: " << input << std::endl;
    else if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
        std::cout << "float: Non displayable" << std::endl;
    else if (status == 3)
        std::cout << "float: " << input + "f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
}

void    ScalarConverter::stringToDouble(std::string input) {
    if (specialValue == true && status == 3)
        std::cout << "double: " << input << std::endl;
    else if (value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max())
        std::cout << "double: Non displayable" << std::endl;
    else if (status == 2)
        std::cout << "double: " << input.erase(input.size() - 1) << std::endl;
    else
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

int    ScalarConverter::parsingValue(std::string input) {
    bool statusfloat = false;
    bool statusdouble = false;
    int i = 0;
    if (input.size() == 1 && !isdigit(input[0]))
        return (0);
    if (input == "-inff" || input ==  "+inff" || input == "nanf") {
        specialValue = true;
        return (2);
    }
    if (input == "-inf" || input ==  "+inf" || input == "nan") {
        specialValue = true;
        return (3);    
    }
    while (input[i]) {
        if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f' && input[i] != '-')
            return (-1);
        if ((i == 0 && input[i] == '.') || (i != 0 && input[i] == '-') || ((int)input.size() == i && input[i] == '.') || ((int)input.size() - 1 == i && input[i] == 'f' && i >= 1 && input[i - 1] == '.'))
            return (-1);   
        if (((int)input.size() - 1 != i && input[i] == 'f'))
            return (-1);
        if (input[i] == '.') {
            if (statusdouble == true)
                return (-1);
            statusdouble = true;  
        }
        if (input[i] == 'f') {
            if (statusfloat == true)
                return (-1);
            statusfloat = true;
        }
        i++;
    }
    if (statusfloat == true)
        return (2);
    if (statusdouble == true)
        return (3);
    return (1);
}