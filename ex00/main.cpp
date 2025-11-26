/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:15:49 by amaury            #+#    #+#             */
/*   Updated: 2025/11/26 09:39:37 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    ScalarConverter value;
    if (argc == 2)
        value.setInput(argv[1]);
    else
        std::cerr << "No arguments found, or too many arguments." << std::endl;
}