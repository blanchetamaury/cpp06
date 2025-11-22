/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:19:55 by amaury            #+#    #+#             */
/*   Updated: 2025/11/22 16:42:14 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
    Data example;
    example.tmp = "hello World !";

    std::cout << "Data = " << example.tmp << std::endl;
    uintptr_t ptr = Serializer::serialize(&example);
    std::cout << "ptr = " << ptr << std::endl;
    std::cout << "Data = " << Serializer::deserialize(ptr)->tmp << std::endl;
}