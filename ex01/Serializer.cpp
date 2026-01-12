/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:10:36 by amaury            #+#    #+#             */
/*   Updated: 2026/01/12 09:00:25 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(Serializer const &other) { (void)other; }
Serializer &Serializer::operator=(Serializer const &other) {
    (void)other;
    return (*this);
}

uintptr_t   Serializer::serialize(Data *ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}