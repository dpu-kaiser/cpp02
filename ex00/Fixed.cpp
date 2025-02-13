/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:06:18 by dkaiser           #+#    #+#             */
/*   Updated: 2025/02/13 13:17:58 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed(void) : raw_value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : raw_value(other.getRawBits()) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::&operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->raw_value = other.getRawBits();
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->raw_value;
}
void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->raw_value = raw;
}
