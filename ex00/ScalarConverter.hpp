/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:21:16 by amaury            #+#    #+#             */
/*   Updated: 2025/11/25 23:37:11 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <iomanip>

class ScalarConverter {
    private:
        long double                 value;   
        bool                        specialValue;
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(std::string input);
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(ScalarConverter const &other);
    
        void    setInput(std::string input);
        void    parsingValue(std::string &input);
        
        void    stringToChar();
        void    stringToInt();
        void    stringTofloat(std::string input);
        void    stringToDouble(std::string input);
};

#endif