/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:06:18 by dkaiser           #+#    #+#             */
/*   Updated: 2025/02/13 16:23:59 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : raw_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    this->raw_value = i << this->fractional_bits;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    float nbr = f;
    for (int i = 0; i < this->fractional_bits; i++)
    {
        nbr *= 2;
    }
    this->raw_value = static_cast<int>(std::round(nbr));
}

Fixed::Fixed(const Fixed &other) : raw_value(other.raw_value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->raw_value = other.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->raw_value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->raw_value = raw;
}

int Fixed::toInt(void) const
{
    return this->raw_value >> this->fractional_bits;
}

float Fixed::toFloat(void) const
{
    float f = static_cast<float>(this->raw_value);
    for (int i = 0; i < this->fractional_bits; i++)
    {
        f /= 2;
    }
    return f;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
