/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:15:49 by amaury            #+#    #+#             */
/*   Updated: 2026/01/09 14:12:47 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc == 2) 
        ScalarConverter::convert(argv[1]);
    else
        std::cerr << "No arguments found, or too many arguments." << std::endl;
}