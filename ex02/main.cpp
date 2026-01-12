/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:44:18 by amaury            #+#    #+#             */
/*   Updated: 2026/01/12 09:06:43 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

Base *generate(void) {
    srand(time(NULL));
    int value = rand() % 3;
    if (value == 0) {
        std::cout << "Create A" << std::endl;
        Base *tmp = new A;
        return (tmp);
    }
    if (value == 1) {
        std::cout << "Create B" << std::endl;
        Base *tmp = new B;
        return (tmp);
    }
    std::cout << "Create C" << std::endl;
    Base *tmp = new C;
    return (tmp);
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "(pointed) Find A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "(pointed) Find B" << std::endl;
    else
        std::cout << "(pointed) Find C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "(referenced) Find A" << std::endl;
    }
    catch(std::exception &e) {
        (void)e;
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "(referenced) Find B" << std::endl;
        }
        catch (std::exception &e) {
            (void)e;
            std::cout << "(referenced) Find C" << std::endl;
        }
    }
}

int main() {
    Base *tmp = generate();

    identify(tmp);
    identify(*tmp);
    delete tmp;
}